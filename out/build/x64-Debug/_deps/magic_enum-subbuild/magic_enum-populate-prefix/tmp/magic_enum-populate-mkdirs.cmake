# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/magic_enum-src"
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/magic_enum-build"
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/magic_enum-subbuild/magic_enum-populate-prefix"
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/magic_enum-subbuild/magic_enum-populate-prefix/tmp"
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/magic_enum-subbuild/magic_enum-populate-prefix/src/magic_enum-populate-stamp"
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/magic_enum-subbuild/magic_enum-populate-prefix/src"
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/magic_enum-subbuild/magic_enum-populate-prefix/src/magic_enum-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/magic_enum-subbuild/magic_enum-populate-prefix/src/magic_enum-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/magic_enum-subbuild/magic_enum-populate-prefix/src/magic_enum-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
