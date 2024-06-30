# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/pugixml-src"
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/pugixml-build"
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/pugixml-subbuild/pugixml-populate-prefix"
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/pugixml-subbuild/pugixml-populate-prefix/tmp"
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/pugixml-subbuild/pugixml-populate-prefix/src/pugixml-populate-stamp"
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/pugixml-subbuild/pugixml-populate-prefix/src"
  "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/pugixml-subbuild/pugixml-populate-prefix/src/pugixml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/pugixml-subbuild/pugixml-populate-prefix/src/pugixml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/prona/Documents/01. Dev/01 - Hacking Training/ModMenuSources/out/build/x64-Debug/_deps/pugixml-subbuild/pugixml-populate-prefix/src/pugixml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
