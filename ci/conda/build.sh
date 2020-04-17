#!/usr/bin/env bash
python binder/generate/run.py

rm -Rf build
mkdir build
cd build

cmake .. -G "Ninja" \
    -DCMAKE_BUILD_TYPE="Release" \
    -DENABLE_SMESH=OFF \
    -DENABLE_NETGEN=OFF \
    -DENABLE_FORCE=OFF \
    -DXCB_INCLUDE_DIR=$PREFIX/include/xcb \
    -DTBB_INCLUDE_DIR=$PREFIX/include

ninja install -j2

cd ..
python setup.py install
