//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_TESTER_TC_RUNNER_H__
#define __SATES_TESTER_TC_RUNNER_H__

#include <sates/define.h>


namespace sates
{
namespace tester
{
class SATES_EXPORT tc_runner
{
public:
    static void run_all();
    static void run_only_enabled();
    static void run_except_disabled();
};
}
}

#endif // __SATES_TESTER_TC_RUNNER_H__

