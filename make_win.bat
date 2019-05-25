@echo off
cls
echo Compiling project...
cd ./ild_compiler/src/
g++ main.cpp Utils/Helper.cpp Utils/Helper.h Parser/Parser.cpp Parser/Parser.h Structures/Data/Nodes/Data_Node.cpp Structures/Data/Nodes/Data_Node.h Structures/Data/Data.h Structures/Data/Stack/Stack.cpp Structures/Data/Stack/Stack.h ild_lib/stdild.cpp ild_lib/stdild.h Compiler/compiler.cpp Compiler/compiler.h -o ../out/compiler
echo Done!
pause