cmake_minimum_required(VERSION 3.11)
project(Example)

# Defines the version of the Application
set(Viewy_VERSION_MAJOR 1)
set(Viewy_VERSION_MINOR 0)

#------------------------------------------------------------------------------
# ITK
#------------------------------------------------------------------------------
find_package(ITK REQUIRED)
#include(${ITK_USE_FILE})
if (NOT ITK_FOUND)
  message("Skipping ${PROJECT_NAME}: ${ITK_NOT_FOUND_MESSAGE}")
  return ()
endif()
message (STATUS "ITK_VERSION: ${ITK_VERSION}")

#------------------------------------------------------------------------------
# VTK
#------------------------------------------------------------------------------
find_package(VTK REQUIRED)
if (NOT VTK_FOUND)
  message("Skipping ${PROJECT_NAME}: ${VTK_NOT_FOUND_MESSAGE}")
endif()
include(${VTK_USE_FILE})
message (STATUS "VTK_VERSION: ${VTK_VERSION} ${VTK_DIR}")

#------------------------------------------------------------------------------
# QT
#------------------------------------------------------------------------------
find_package(Qt5Widgets REQUIRED QUIET)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# Instruct CMake to run uic automatically (ui compiler)
set(CMAKE_AUTOUIC ON)
# Instruct CMake where to find the UI files
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/UI)
#qt5_add_resources(RESOURCES_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/Resources/resources.qrc)

# Add an option to display the console or not
if(WIN32)
  option(DISPLAY_CONSOLE "Display the windows console in the background" OFF)
endif()

if(NOT ${DISPLAY_CONSOLE})
  set(CONSOLE_WIN32 WIN32)
endif()

#------------------------------------------------------------------------------
# Executable
#------------------------------------------------------------------------------
add_executable(Example ${CONSOLE_WIN32})

#------------------------------------------------------------------------------
# Target
#------------------------------------------------------------------------------
# Define target sources
target_sources(Example PRIVATE
# UI
  UI/MainWindow.ui
  ${RESOURCES_SRCS}
# SRC/Interface
  Sources/Interface/MainWindow.cxx
  Sources/Interface/MainWindow.h
  Sources/Interface/VTKOpenGLWidget.cxx
  Sources/Interface/VTKOpenGLWidget.h
# SRC
  Sources/Main.cxx
)

#qt5_use_modules(${PROJECT_NAME} Widgets Core Gui)
target_link_libraries(Example ${VTK_LIBRARIES} ${ITK_LIBRARIES})
target_include_directories(Example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/Sources ${CMAKE_CURRENT_BINARY_DIR})

target_compile_definitions(Example 
  PRIVATE APP_VERSION_MAJOR=${Example_VERSION_MAJOR}
  PRIVATE APP_VERSION_MINOR=${Example_VERSION_MINOR}
  )

# As we want to use filesystem, c++17 has to be used
set_property(TARGET Example PROPERTY CXX_STANDARD 17)

# Get the sources of the target
get_target_property(Example_sources Example SOURCES)
# Keep the directory structure in VS (only for target's sources)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${Example_sources})

## Installation
#install(TARGETS Example DESTINATION bin)
#
## Install Qt5
#include(CMake/DeployQt5.cmake)
#set(QT5_COMPONENTS 
#	Core 
#	Widgets
#	Gui 
#	)
#find_package(Qt5 COMPONENTS ${QT5_COMPONENTS})
#install_qt5_lib(bin ${QT5_COMPONENTS})
#install_qt5_platform(bin)
