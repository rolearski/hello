 #!/bin/bash 

#make clean
rm -f CMakeCache.txt
find . -name CMakeFiles | xargs rm -Rf

#set +e
#exit

# -DVMIME_HAVE_TLS_SUPPORT=OFF
# -DCPP_STANDARD=-std=c++2a
# -DCXX_STANDARD=-std=c++2a

# -DLIBRESSL_VERSION_NUMBER=3

#cmake -DBOOST_ROOT=$HOME/opt/boost_1_70_0 -Wno-dev -Wno-misleading-indentation \
# -DCMAKE_BUILD_TYPE=Debug   .

#cmake -DBOOST_ROOT=$HOME/opt/boost_1_70_0 -Wno-dev \
#cmake -DBOOST_ROOT=$HOME/opt/boost_1_70_0  \
# -DCMAKE_BUILD_TYPE=Release .

#cmake -DBOOST_ROOT=$HOME/opt/boost_1_70_0 .




#cmake -DBOOST_ROOT=$HOME/opt/boost_1_74_0  -DCMAKE_BUILD_TYPE=Debug .


#cmake -DLIBRESSL_VERSION_NUMBER=3 -DCMAKE_BUILD_TYPE=Debug .
cmake -DCMAKE_BUILD_TYPE=Debug .





