#!/usr/bin/env bash

rm -Rf build
mkdir build
cd build


python binder/run.py -o ../

# export CC=gcc-4.9
# export CXX=g++-4.9


cmake .. -G "Ninja" \
    -DCMAKE_BUILD_TYPE="Release" \
    -DENABLE_SMESH=OFF \
    -DENABLE_NETGEN=OFF \
    -DENABLE_FORCE=OFF \
    -DTBB_INCLUDE_DIR=$PREFIX/include

ninja install -j2

cd ..
python setup.py install
