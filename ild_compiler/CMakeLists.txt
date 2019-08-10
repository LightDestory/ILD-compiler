cmake_minimum_required(VERSION 3.14)
project(ild_compiler)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH "../output")
add_executable(ild_compiler
        ./src/main.cpp
        ./src/Utils/Helper.cpp
        ./src/Utils/Helper.h
        ./src/Parser/Parser.cpp
        ./src/Parser/Parser.h
        ./src/Structures/Data/Nodes/Data_Node.cpp
        ./src/Structures/Data/Nodes/Data_Node.h
        ./src/Structures/Data/Data.h
        ./src/Structures/Data/Stack/Stack.cpp
        ./src/Structures/Data/Stack/Stack.h
        ./src/ild_lib/stdild.cpp
        ./src/ild_lib/stdild.h
        ./src/Compiler/compiler.cpp
        ./src/Compiler/compiler.h
        )