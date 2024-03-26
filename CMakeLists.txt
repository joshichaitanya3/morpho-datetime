
cmake_minimum_required(VERSION 3.13)
project(morpho-datetime)

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# Build the library as a plugin
add_library(datetime MODULE "")

# Suppress 'lib' prefix
set_target_properties(datetime PROPERTIES PREFIX "")

# Add sources
add_subdirectory(src)

# Locate the morpho.h header file and store in MORPHO_HEADER
find_file(MORPHO_HEADER
          morpho.h
          HINTS
          /usr/local/opt/morpho
          /opt/homebrew/opt/morpho
          /usr/local/include/morpho
          )

# Identify folder that morpho.h is located in from MORPHO_HEADER and store in MORPHO_INCLUDE
get_filename_component(MORPHO_INCLUDE ${MORPHO_HEADER} DIRECTORY)

# Add morpho headers to MORPHO_INCLUDE
target_include_directories(datetime PUBLIC ${MORPHO_INCLUDE})

# Add general header search paths
target_include_directories(datetime PUBLIC /usr/local/include)

# Add morpho headers in subfolders to MORPHO_INCLUDE
file(GLOB morpho_subdirectories LIST_DIRECTORIES true ${MORPHO_INCLUDE}/*)
foreach(dir ${morpho_subdirectories})
    IF(IS_DIRECTORY ${dir})
        target_include_directories(datetime PUBLIC ${dir})
    ELSE()
        CONTINUE()
    ENDIF()
endforeach()

# Locate libmorpho
find_library(MORPHO_LIBRARY
    NAMES morpho libmorpho
)

# Add directory for the rust dylib
target_link_libraries(datetime ${MORPHO_LIBRARY} ${CMAKE_SOURCE_DIR}/src/datetimers/target/release/libdatetimers.dylib)

set(CMAKE_INSTALL_PREFIX ..)

# Install the resulting binary
install(TARGETS datetime LIBRARY DESTINATION lib/)
