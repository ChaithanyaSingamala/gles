cmake_minimum_required(VERSION 3.7.1)

SET(CMAKE_INSTALL_PREFIX "install" CACHE PATH "install prefix" FORCE) 


set(NAME "OpenGL")

SET(TARGET_NAME "vc2015-powervrsdk-win32" CACHE STRING "should be set to correct target") 
set_property(CACHE TARGET_NAME PROPERTY STRINGS "vc2015-powervrsdk-win32;vc2015-powervrsdk-x64")


project(${NAME})

set(PATH_TARGET_DIR "target")

add_definitions(-DGL_GLEXT_PROTOTYPES)

include_directories(${PATH_TARGET_DIR}/${TARGET_NAME}/usr/include)

link_directories(${PATH_TARGET_DIR}/${TARGET_NAME}/usr/lib)

if(WIN32)
    source_group("common" REGULAR_EXPRESSION "renderer/core/common/*")
    source_group("gl" REGULAR_EXPRESSION "renderer/core/gl/*")
    source_group("test" REGULAR_EXPRESSION "renderer/test/*")
endif(WIN32)

file(GLOB_RECURSE CPP_FILES 
							${CMAKE_CURRENT_SOURCE_DIR}/renderer/core/common/*.cpp
							${CMAKE_CURRENT_SOURCE_DIR}/renderer/core/gl/*.cpp
							${CMAKE_CURRENT_SOURCE_DIR}/renderer/test/*.cpp
							)
							
file(GLOB_RECURSE HPP_FILES 
							${CMAKE_CURRENT_SOURCE_DIR}/renderer/core/common/*.h
							${CMAKE_CURRENT_SOURCE_DIR}/renderer/core/gl/*.h
							${CMAKE_CURRENT_SOURCE_DIR}/renderer/test/*.h
							)

LINK_LIBRARIES( 
							libEGL 
							libGLESv2
						)							
							
add_executable(${NAME} ${CPP_FILES} ${HPP_FILES})



# Define project properties
set_property(TARGET ${NAME} PROPERTY RUNTIME_OUTPUT_DIRECTORY 					${CMAKE_CURRENT_SOURCE_DIR}/bin/${TARGET_NAME})
set_property(TARGET ${NAME} PROPERTY RUNTIME_OUTPUT_DIRECTORY_DEBUG 			${CMAKE_CURRENT_SOURCE_DIR}/bin/${TARGET_NAME})
set_property(TARGET ${NAME} PROPERTY RUNTIME_OUTPUT_DIRECTORY_RELEASE 			${CMAKE_CURRENT_SOURCE_DIR}/bin/${TARGET_NAME})
set_property(TARGET ${NAME} PROPERTY RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL 		${CMAKE_CURRENT_SOURCE_DIR}/bin/${TARGET_NAME})
set_property(TARGET ${NAME} PROPERTY RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO 	${CMAKE_CURRENT_SOURCE_DIR}/bin/${TARGET_NAME})

# Define C++ version to be used for building the project
set_property(TARGET ${NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

# Define C version to be used for building the project
set_property(TARGET ${NAME} PROPERTY C_STANDARD 99)
set_property(TARGET ${NAME} PROPERTY C_STANDARD_REQUIRED ON)

