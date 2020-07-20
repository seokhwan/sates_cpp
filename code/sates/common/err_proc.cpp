#include "err_proc.h"
namespace sates
{
namespace common
{

void err_proc(const char* p_err_msg)
{
    std::cout << p_err_msg << std::endl;
    exit(EXIT_FAILURE);
}


}
}

