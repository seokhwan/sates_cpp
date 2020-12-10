//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/sates.h>
#include <thread>
#include <chrono>

SATES_TEST_RUN(TC_PROCESS_RUN_KILL)
{
    std::string str_cmd = "ping 127.0.0.1";
    auto process_id = sates::process_run(str_cmd.c_str(), str_cmd.size());
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto result = sates::process_kill(process_id);
    SATES_FALSE(result < 0);

}


SATES_TEST_RUN(TC_NG_TEST)
{
    SATES_EQ(0, 1);
    SATES_NE(1, 1);
    SATES_TRUE(false);
}



