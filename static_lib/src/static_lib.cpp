
#include <static_lib.h>
#include <iostream>

namespace static_lib
{
    void static_lib_class::call()
    {
        std::cout << " yo, this be static lib callin'" << std::endl;
    }
}