python binder/generate/run.py -c config.txt
if errorlevel 1 exit 1

mkdir build
cd build

cmake .. -G "Ninja" ^
    -DCMAKE_BUILD_TYPE="Release" ^
    -DENABLE_SMESH=ON ^
    -DENABLE_NETGEN=ON ^
    -DENABLE_FORCE=OFF ^
    -DPTHREAD_INCLUDE_DIRS:FILEPATH="%LIBRARY_PREFIX%/include"
if errorlevel 1 exit 1

ninja -j1
if errorlevel 1 exit 1

ninja install -j1
if errorlevel 1 exit 1

cd ..
python setup.py install --prefix="%PREFIX%"
