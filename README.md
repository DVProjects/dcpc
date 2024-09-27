# Davide's C+ compiler
Compiler for my own 'dialect' of the c language.
The c+ language main idea is to give c OOP features without getting too high-level with the language.
This compiler is built to receive c+ files, pre-process them and compile them to standard c files (.i).
C+ files are passed through the c pre-processor (cpp) to avoid having to also pass headers to the compiler.

Compilation process:
dcpc file.c+
gcc file.i
