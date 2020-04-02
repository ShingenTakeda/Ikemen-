#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include <math.h>
#include <fstream>
#include <cstdarg>

class Common
{
    public:
        //Message whoever made this and ask them what this does
        /*
        IMax = int32(^uint32(0) >> 1)
	    IErr = ^IMax
        */

        int32_t Random();
        int Srand(int32_t s);
        int32_t Rand(int32_t min, int32_t max);
        int32_t RandI(int32_t min, int32_t max);
        
        //Make this two functions type float 32 bits
        _Float32 RandF();
        _Float32 RandF32();

        ///SearchFile returns the directory that file is located
        ///This search on deffile directory, then it keeps looking on other dirs
        std::string SearchFile(std::string file, std::string deffile);

    private:
        //Look up Variadic functions and arguments
        va_list arg;

        int Max(int32_t max);
        int Min(int32_t min);
};