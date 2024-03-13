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



# Link libraries
#target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# find_package(depthai CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME}
    PRIVATE ${OpenCV_LIBS}
    PRIVATE depthai::opencv
)