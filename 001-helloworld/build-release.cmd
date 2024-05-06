mkdir output
rmdir /s /q output\Release

cmake . -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Release -DPLATFORM=win64 -B output
cmake --build output --config Release