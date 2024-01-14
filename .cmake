#!/bin/bash 

#make clean
rm -f CMakeCache.txt
find . -name CMakeFiles | xargs rm -Rf

cmake -DCMAKE_BUILD_TYPE=Debug .





