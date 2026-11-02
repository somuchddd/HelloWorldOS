
#!/bin/bash

set -e

cd "$(dirname "$0")"

echo "Updating source code from Git"

git pull --rebase

echo "Configuring CMake"

cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

echo "Building project"

cmake --build build

echo "Running program"

./build/hello

echo "Finished successfully!"

