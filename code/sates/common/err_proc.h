//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_COMMON_ERR_PROC_H__
#define __SATES_COMMON_ERR_PROC_H__

#include <sates/define.h>
#include <iostream>

namespace sates
{
namespace common
{

template <typename Func, typename ... Args>
void err_proc(const char* p_err_msg, Func f, Args ... args)
{
    std::cout << p_err_msg << std::endl;
    f(args...);
}

SATES_EXPORT void err_proc(const char* p_err_msg);


}
}

#endif // __SATES_COMMON_ERR_PROC_H__

