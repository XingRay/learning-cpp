mkdir build
cd build

rmdir /s /q .\Release

cmake .. -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Debug -DPLATFORM=win64
cmake --build . --config Debug