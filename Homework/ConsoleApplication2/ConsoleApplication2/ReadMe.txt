Compiler : Visual C++, but it should work with compilers, like g++ or gcc. I test it on Visual C++, because it's default
 compiler for Visual Studio 2017.

Files stdafx.h, stdafx.cpp and targetver.h
 Visual studion insist that stdafx.h is included in every .cpp file.
 stdafx's are used for faster building projet.
 targetver.h ensures that program will start on older versions of VS.

if some of this files creates a problem at compiling, just paste a comment befor every single line that includes - 
#include "stdafx.h"; 

