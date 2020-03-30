#include <string>
#include <iostream>
#include <cstdint>
#include <math.h>

class Common
{
    public:
        //Message whoever made this and ask them what this does
        /*
        IMax = int32(^uint32(0) >> 1)
	    IErr = ^IMax
        */

        int32_t Random();

        ///SearchFile returns the directory that file is located
        ///This search on deffile directory, then it keep looking on other dirs
        std::string SearchFile(std::string file, std::string deffile);

    private:
        int Max(int32_t max);
        int Min(int32_t min);
};