##################################################    Project     ##################################################
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project               (hdf VERSION 1.0 LANGUAGES CXX)
list                  (APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set_property          (GLOBAL PROPERTY USE_FOLDERS ON)
set                   (CMAKE_CXX_STANDARD 20)

include               (set_max_warning_level)
set_max_warning_level ()

##################################################    Options     ##################################################
option(BUILD_TESTS "Build tests." OFF)

##################################################    Sources     ##################################################
file(GLOB_RECURSE PROJECT_HEADERS include/*.h include/*.hpp)
file(GLOB_RECURSE PROJECT_CMAKE_UTILS cmake/*.cmake)
file(GLOB_RECURSE PROJECT_MISC *.md *.txt)
set (PROJECT_FILES 
  ${PROJECT_HEADERS} 
  ${PROJECT_CMAKE_UTILS} 
  ${PROJECT_MISC})

include            (assign_source_group)
assign_source_group(${PROJECT_FILES})

##################################################  Dependencies  ##################################################
include(import_library)

set           (HDF5_PREFER_PARALLEL TRUE)
find_package  (HDF5 REQUIRED)
import_library(HDF5_INCLUDE_DIRS HDF5_C_LIBRARIES)
list          (APPEND PROJECT_COMPILE_DEFINITIONS -DH5_BUILT_AS_DYNAMIC_LIB)

##################################################    Targets     ##################################################
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  $<INSTALL_INTERFACE:include>)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_INCLUDE_DIRS})
target_link_libraries     (${PROJECT_NAME} INTERFACE ${PROJECT_LIBRARIES})
target_compile_definitions(${PROJECT_NAME} INTERFACE ${PROJECT_COMPILE_DEFINITIONS})

# Hack for header-only project to appear in the IDEs.
add_library(${PROJECT_NAME}_ STATIC ${PROJECT_FILES})
target_include_directories(${PROJECT_NAME}_ PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/include 
  ${CMAKE_CURRENT_BINARY_DIR})     
target_include_directories(${PROJECT_NAME}_ PUBLIC ${PROJECT_INCLUDE_DIRS})
target_link_libraries     (${PROJECT_NAME}_ PUBLIC ${PROJECT_LIBRARIES})
target_compile_definitions(${PROJECT_NAME}_ PUBLIC ${PROJECT_COMPILE_DEFINITIONS})
set_target_properties     (${PROJECT_NAME}_ PROPERTIES LINKER_LANGUAGE CXX)

##################################################    Testing     ##################################################
if(BUILD_TESTS)
  enable_testing     ()
  set                (TEST_MAIN_NAME test_main)
  set                (TEST_MAIN_SOURCES tests/internal/main.cpp)
  add_library        (${TEST_MAIN_NAME} OBJECT ${TEST_MAIN_SOURCES})
  set_property       (TARGET ${TEST_MAIN_NAME} PROPERTY FOLDER tests)
  assign_source_group(${TEST_MAIN_SOURCES})

  file(GLOB PROJECT_TEST_CPPS tests/*.cpp)
  foreach(_SOURCE ${PROJECT_TEST_CPPS})
    get_filename_component(_NAME ${_SOURCE} NAME_WE)
    add_executable        (${_NAME} ${_SOURCE} $<TARGET_OBJECTS:${TEST_MAIN_NAME}>)
    target_link_libraries (${_NAME} ${PROJECT_NAME})
    add_test              (${_NAME} ${_NAME})
    set_property          (TARGET ${_NAME} PROPERTY FOLDER tests)
    assign_source_group   (${_SOURCE})
  endforeach()
endif()

##################################################  Installation  ##################################################
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-config)
install(DIRECTORY include/ DESTINATION include)
install(EXPORT  ${PROJECT_NAME}-config DESTINATION cmake)
export (TARGETS ${PROJECT_NAME}        FILE        ${PROJECT_NAME}-config.cmake)
