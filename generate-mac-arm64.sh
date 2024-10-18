#!/bin/bash

BUILD_PROJECT=1

BUILD_DIR="$(pwd)/.build/macos.arm64"

while getopts bi flag
do
    case "${flag}" in
        b) BUILD_PROJECT=1;;
    esac
done

echo ============== Config project ==============
cmake -G "Ninja" -S . -B "${BUILD_DIR}" -DCMAKE_OSX_DEPLOYMENT_TARGET=11.0 -DPROJECT_ARCH=arm64  -DCEFVIEW_LIB_NAME=QCefView_debug  -DCEFVIEW_WING_NAME=CefViewWing -DCMAKE_DEBUG_POSTFIX=_debug -DBUILD_DEMO=ON -DUSE_SANDBOX=OFF -DCMAKE_INSTALL_PREFIX:PATH="$(pwd)/out/macos.arm64" $*

if [ ${BUILD_PROJECT} -eq 1 ] 
then
    echo ============== Build project ==============
    cmake --build "${BUILD_DIR}"
fi
