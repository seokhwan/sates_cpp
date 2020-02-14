#!/bin/bash

CUR_DIR=$(pwd)

cd ../../
rm -rf build_linux
mkdir -p build_linux/debug
mkdir -p build_linux/release

cd build_linux/debug
cmake ../../code -DSATES_LINUX:STRING=yes -DCMAKE_BUILD_TYPE="Debug"

cd ../release
cmake ../../code -DSATES_LINUX:STRING=yes -DCMAKE_BUILD_TYPE="Release"

cd $CUR_DIR

