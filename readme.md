# C++ Boilerplate
[![Build Status](https://app.travis-ci.com/siddharthtelang/Valgrind_Exercise.svg?branch=valgrind_exercise)](https://app.travis-ci.com/siddharthtelang/Valgrind_Exercise)
---

## Overview

Simple starter C++ project with:

- cmake
- valgrind

## Standard install via command-line
```
git clone --recursive -b valgrind_exercise https://github.com/siddharthtelang/Valgrind_Exercise.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run program: ./app/shell-app
```

## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Valgrind Profiling
Resuts are availabe in results/before_fix and results/after_fix.

Run the following commands
```
cd <path to repository>
cd build
valgrind ./app/shell-app
valgrind --tool=helgrind ./app/shell-app
valgrind --leak-check=full --show-leak-kinds=all ./app/shell-app
```
For memory profiler
```
valgrind --tool=callgrind ./app/shell-app
```
Open the genterated callgrind file in KCachegrind for GUI visualization

## Cppcheck and Cpplint
Results are stored in results/cpplint_cppcheck.txt

## Working with Eclipse IDE ##

## Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive -b valgrind_exercise https://github.com/siddharthtelang/Valgrind_Exercise.git
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../cpp-boilerplate/
```