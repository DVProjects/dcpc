# Davide's C+ compiler
The C+ language's main idea is to give C OOP features without getting too high-level with the language.
This compiler is built to receive C+ files, preprocess them, and transpile them to standard C files (.i).
C+ files are passed through the C preprocessor (cpp) to avoid having to pass headers to the compiler.

Compilation process:
    dcpc file.c+
    gcc file.i
