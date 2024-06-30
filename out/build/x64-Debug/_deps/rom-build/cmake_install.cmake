# Install script for directory: C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/rom-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "CMAKE_OBJDUMP-NOTFOUND")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/asynclogger-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/cpp-semver-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/cxxopts-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/json-build/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/rom-build/lua52.lib")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/sol2-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/magic_enum-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/polyhook-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/pugixml-build/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/toml++-build/cmake_install.cmake")
endif()

