import subprocess
import re

def get_dependencies(binary_path):
    output = subprocess.check_output(["ldd", binary_path]).decode("utf-8")
    dependencies = []

    for line in output.split("\n"):
        match = re.search(r"\s*(.+)\s+=>\s+(.+)\s+\(0x", line)
        if match:
            library = match.group(1)
            dependencies.append(library)

    return dependencies

def generate_cpack_dependencies(dependencies):
    cpack_dependencies = []

    for dependency in dependencies:
        try:
            output = subprocess.check_output(["dpkg", "-S", dependency]).decode("utf-8")
            package_name = output.split(":")[0]

            try:
                version_output = subprocess.check_output(["dpkg", "-s", package_name]).decode("utf-8")
                version_match = re.search(r"Version:\s+(.+)", version_output)
                if version_match:
                    version = version_match.group(1)
                    # Remove epoch if present
                    version = version.split(':', 1)[-1]
                    cpack_dependency = f"{package_name} (>= {version})"
                    cpack_dependencies.append(cpack_dependency)
            except subprocess.CalledProcessError:
                print(f"Warning: Unable to get version for package '{package_name}'. Skipping version constraint.")
                cpack_dependencies.append(package_name)
                
        except subprocess.CalledProcessError:
            print(f"Warning: No package found for dependency '{dependency}'. You may need to manually specify this dependency.")

    return cpack_dependencies


# Print dep
binary_path = "build/oaktest"
dependencies = get_dependencies(binary_path)
cpack_dependencies = generate_cpack_dependencies(dependencies)
print("CPack Dependencies:")
for dep in cpack_dependencies:
    print(dep)

# Format for CPack
cpack_dependencies_str = ", ".join([f'{dep}' for dep in cpack_dependencies])
cpack_command = f'set(CPACK_DEBIAN_PACKAGE_DEPENDS {cpack_dependencies_str})'

print("CPack Command:")
print(cpack_command)
