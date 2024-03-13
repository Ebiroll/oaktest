cmake_minimum_required(VERSION 3.10)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/depthai-core EXCLUDE_FROM_ALL)

# Set the project name
project(oaktest)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(${PROJECT_NAME} main.cpp)

# Find packages
find_package(OpenCV REQUIRED)
#find_package(depthai REQUIRED CONFIG PATHS ${depthai_DIR} NO_DEFAULT_PATH)

# Include directories for compiling
include_directories(${OpenCV_INCLUDE_DIRS})


# include_directories(depthai-core/include)

set(CMAKE_INSTALL_LIBDIR "/usr/lib")

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "olof.astrand@gmail.com")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libopencv-highgui4.2 (>= 4.2.0+dfsg-5), libopencv-imgproc4.2 (>= 4.2.0+dfsg-5), libopencv-core4.2 (>= 4.2.0+dfsg-5), libusb-1.0-0 (>= 1.0.23-2build1), libc6-i386 (>= 2.31-0ubuntu9.14), libstdc++6 (>= 10.5.0-1ubuntu1~20.04), libc6-i386 (>= 2.31-0ubuntu9.14), libgcc-s1 (>= 10.5.0-1ubuntu1~20.04), libc6 (>= 2.31-0ubuntu9.14), libgtk-3-0 (>= 3.24.20-0ubuntu1.1), libgtk-3-0 (>= 3.24.20-0ubuntu1.1), libcairo2 (>= 1.16.0-4ubuntu1), libgdk-pixbuf2.0-0 (>= 2.40.0+dfsg-3ubuntu0.4), libglib2.0-0 (>= 2.64.6-1~ubuntu20.04.6), libglib2.0-0 (>= 2.64.6-1~ubuntu20.04.6), libopencv-imgcodecs4.2 (>= 4.2.0+dfsg-5), libc6-i386 (>= 2.31-0ubuntu9.14), zlib1g (>= 1.2.11.dfsg-2ubuntu1.5), libtbb2 (>= 2020.1-2), libglib2.0-0 (>= 2.64.6-1~ubuntu20.04.6), libpangocairo-1.0-0 (>= 1.44.7-2ubuntu4), libx11-6 (>= 1.6.9-2ubuntu1.6), libxi6 (>= 1.7.10-0ubuntu1), libxfixes3 (>= 5.0.3-2), libcairo-gobject2 (>= 1.16.0-4ubuntu1), libatk1.0-0 (>= 2.35.1-1ubuntu2), libatk-bridge2.0-0 (>= 2.34.2-0ubuntu2~20.04.1), libepoxy0 (>= 1.5.4-1), libfribidi0 (>= 1.0.8-2ubuntu0.1), libglib2.0-0 (>= 2.64.6-1~ubuntu20.04.6), libpangoft2-1.0-0 (>= 1.44.7-2ubuntu4), libpango-1.0-0 (>= 1.44.7-2ubuntu4), libharfbuzz0b (>= 2.6.4-1ubuntu4.2), libfontconfig1 (>= 2.13.1-2ubuntu3), libfreetype6 (>= 2.10.1-2ubuntu0.3), libxinerama1 (>= 1.1.4-2), libxrandr2 (>= 1.5.2-0ubuntu1), libxcursor1 (>= 1.2.0-2), libxcomposite1 (>= 0.4.5-1), libxdamage1 (>= 1.1.5-2), libxkbcommon0 (>= 0.10.0-1), libwayland-cursor0 (>= 1.18.0-1ubuntu0.1), libwayland-egl1 (>= 1.18.0-1ubuntu0.1), libwayland-client0 (>= 1.18.0-1ubuntu0.1), libxext6 (>= 1.3.4-0ubuntu1), libc6 (>= 2.31-0ubuntu9.14), libpixman-1-0 (>= 0.38.4-0ubuntu2.1), libpng16-16 (>= 1.6.37-2), libxcb-shm0 (>= 1.14-2), libxcb1 (>= 1.14-2), libxcb-render0 (>= 1.14-2), libxrender1 (>= 0.9.10-1), conda (>= 24.1.2-0), libpcre3 (>= 8.39-12ubuntu0.1), libjpeg-turbo8 (>= 2.0.3-0ubuntu1.20.04.3), libwebp6 (>= 0.6.1-2ubuntu0.20.04.3), libgdcm3.0 (>= 3.0.5-1.1ubuntu2), libtiff5 (>= 4.1.0+git191117-2ubuntu0.20.04.12), libopenexr24 (>= 2.3.0-6ubuntu0.5), libgdal26 (>= 3.0.4+dfsg-1build3), libgdcm3.0 (>= 3.0.5-1.1ubuntu2), libdbus-1-3 (>= 1.12.16-2ubuntu2.3), libatspi2.0-0 (>= 2.36.0-2), libmount1 (>= 2.34-0.1ubuntu9.4), libselinux1 (>= 3.0-1build2), libc6 (>= 2.31-0ubuntu9.14), libthai0 (>= 0.1.28-3), libgraphite2-3 (>= 1.3.13-11build1), conda (>= 24.1.2-0), conda (>= 24.1.2-0), libxau6 (>= 1.0.9-0ubuntu1), libxdmcp6 (>= 1.1.3-0ubuntu1), libgdcm3.0 (>= 3.0.5-1.1ubuntu2), libgdcm3.0 (>= 3.0.5-1.1ubuntu2), libgdcm3.0 (>= 3.0.5-1.1ubuntu2), libgdcm3.0 (>= 3.0.5-1.1ubuntu2), libopenjp2-7 (>= 2.3.1-1ubuntu4.20.04.1), libcharls2 (>= 2.0.0+dfsg-1build1), libjson-c4 (>= 0.13.1+dfsg-7ubuntu0.3), libgdcm3.0 (>= 3.0.5-1.1ubuntu2), libgdcm3.0 (>= 3.0.5-1.1ubuntu2), conda (>= 24.1.2-0), conda (>= 24.1.2-0), libjbig0 (>= 2.1-3.1ubuntu0.20.04.1), libilmbase24 (>= 2.3.0-6build1), libilmbase24 (>= 2.3.0-6build1), libilmbase24 (>= 2.3.0-6build1), libarmadillo9 (>= 9.800.4+dfsg-1build1), libpoppler97 (>= 0.86.1-0ubuntu1.4), libfreexl1 (>= 1.0.5-3), libqhull7 (>= 2015.2-4), libgeos-c1v5 (>= 3.8.0-1build1), libepsilon1 (>= 0.9.2+dfsg-4), libodbc1 (>= 2.3.6-0.1build1), odbcinst1debian2 (>= 2.3.6-0.1build1), libkmlbase1 (>= 1.3.0-8build1), libkmldom1 (>= 1.3.0-8build1), libkmlengine1 (>= 1.3.0-8build1), libxerces-c3.2 (>= 3.2.2+debian-1ubuntu0.2), libnetcdf15 (>= 4.7.3-1), libhdf5-103 (>= 1.10.4+repack-11ubuntu1), libhdf4-0-alt (>= 4.2.14-1ubuntu1), libhdf4-0-alt (>= 4.2.14-1ubuntu1), libogdi4.1 (>= 4.1.0+ds-1build1), libgif7 (>= 5.1.9-1), libgeotiff5 (>= 1.5.1-2), libcfitsio8 (>= 3.470-3), libpq5 (>= 12.18-0ubuntu0.20.04.1), libproj15 (>= 6.3.1-1), libdapclient6v5 (>= 3.20.5-1), libdap25 (>= 3.20.5-1), libspatialite7 (>= 4.3.0a-6build1), libcurl3-gnutls (>= 7.68.0-1ubuntu2.21), libfyba0 (>= 4.1.1-6build1), libxml2 (>= 2.9.10+dfsg-5ubuntu0.20.04.7), libmysqlclient21 (>= 8.0.36-0ubuntu0.20.04.1), libssl1.1 (>= 1.1.1f-1ubuntu2.22), libsystemd0 (>= 245.4-4ubuntu3.23), libblkid1 (>= 2.34-0.1ubuntu9.4), conda (>= 24.1.2-0), libdatrie1 (>= 0.2.12-3), libbsd0 (>= 0.10.0-1), libblas3 (>= 3.9.0-1build1), liblapack3 (>= 3.9.0-1build1), libarpack2 (>= 3.7.0-3), libsuperlu5 (>= 5.2.1+dfsg1-4), liblcms2-2 (>= 2.9-4), libnss3 (>= 3.49.1-1ubuntu1.9), libnss3 (>= 3.49.1-1ubuntu1.9), libnspr4 (>= 4.25-1), libgeos-3.8.0 (>= 3.8.0-1build1), libltdl7 (>= 2.4.6-14), libminizip1 (>= 1.1-8build1), liburiparser1 (>= 0.9.3-2), libicu66 (>= 66.1-2ubuntu2.1), libhdf5-103 (>= 1.10.4+repack-11ubuntu1), libsz2 (>= 1.0.4-1), libbz2-1.0 (>= 1.0.8-2), libssl1.1 (>= 1.1.1f-1ubuntu2.22), libgssapi-krb5-2 (>= 1.17-6ubuntu4.4), libldap-2.4-2 (>= 2.4.49+dfsg-2ubuntu1.10), conda (>= 24.1.2-0), conda (>= 24.1.2-0), libidn2-0 (>= 2.2.0-2), librtmp1 (>= 2.4+20151223.gitfa8646d.1-2build1), libssh-4 (>= 0.9.3-2ubuntu2.5), libpsl5 (>= 0.21.0-1ubuntu1), libnettle7 (>= 3.5.1+really3.5.1-2ubuntu0.2), libgnutls30 (>= 3.6.13-2ubuntu1.10), libldap-2.4-2 (>= 2.4.49+dfsg-2ubuntu1.10), libbrotli1 (>= 1.0.7-6ubuntu0.1), libfyba0 (>= 4.1.1-6build1), libfyba0 (>= 4.1.1-6build1), liblz4-1 (>= 1.9.2-2ubuntu0.20.04.1), libgcrypt20 (>= 1.8.5-5ubuntu1.1), libgfortran5 (>= 10.5.0-1ubuntu1~20.04), libnss3 (>= 3.49.1-1ubuntu1.9), libnspr4 (>= 4.25-1), libnspr4 (>= 4.25-1), libicu66 (>= 66.1-2ubuntu2.1), libaec0 (>= 1.0.4-1), conda (>= 24.1.2-0), libk5crypto3 (>= 1.17-6ubuntu4.4), libcom-err2 (>= 1.45.5-2ubuntu1.1), conda (>= 24.1.2-0), libsasl2-2 (>= 2.1.27+dfsg-2ubuntu0.1), libgssapi3-heimdal (>= 7.7.0+dfsg-1ubuntu1.4), libunistring2 (>= 0.9.10-2), libhogweed5 (>= 3.5.1+really3.5.1-2ubuntu0.2), libgmp10 (>= 6.2.0+dfsg-4ubuntu0.1), libp11-kit0 (>= 0.23.20-1ubuntu0.1), libtasn1-6 (>= 4.16.0-2), libbrotli1 (>= 1.0.7-6ubuntu0.1), libgpg-error0 (>= 1.37-1), libquadmath0 (>= 10.5.0-1ubuntu1~20.04), libkeyutils1 (>= 1.6-6ubuntu1.1), libheimntlm0-heimdal (>= 7.7.0+dfsg-1ubuntu1.4), libkrb5-26-heimdal (>= 7.7.0+dfsg-1ubuntu1.4), libasn1-8-heimdal (>= 7.7.0+dfsg-1ubuntu1.4), libhcrypto4-heimdal (>= 7.7.0+dfsg-1ubuntu1.4), libroken18-heimdal (>= 7.7.0+dfsg-1ubuntu1.4), libwind0-heimdal (>= 7.7.0+dfsg-1ubuntu1.4), libheimbase1-heimdal (>= 7.7.0+dfsg-1ubuntu1.4), libhx509-5-heimdal (>= 7.7.0+dfsg-1ubuntu1.4), libcrypt1 (>= 4.4.10-10ubuntu4)")
install(FILES build/oaktest DESTINATION "/opt/depthtest")
install(FILES  build/depthai-core/libdepthai-core.a DESTINATION "${CMAKE_INSTALL_LIBDIR}")
set(OUTPUT_PATH "/opt/depthtest")
include(CPack)

# Link libraries
#target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# find_package(depthai CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME}
    PRIVATE ${OpenCV_LIBS}
    PRIVATE depthai::opencv
)