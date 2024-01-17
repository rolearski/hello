#!/bin/bash 

#make clean
rm -f CMakeCache.txt
find . -name CMakeFiles | xargs rm -Rf

# -DCPP_STANDARD=-std=c++2a
# -DCXX_STANDARD=-std=c++2a

cmake -DCMAKE_BUILD_TYPE=Debug .





