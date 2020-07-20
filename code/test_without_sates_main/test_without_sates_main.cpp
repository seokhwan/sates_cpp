//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/sates.h>


SATES_TEST_RUN(TC_NG_01)
{
    SATES_EQ(0, 1);
    SATES_NE(1, 1);
    SATES_TRUE(false);
}

SATES_TEST_RUN(TC_NG_02)
{
    SATES_EQ(0, 1);
    SATES_NE(1, 1);
    SATES_TRUE(false);
}

SATES_TEST_RUN(TC_OK_03)
{
    SATES_EQ(1, 1);
}

const char* custom_arg[] = { {"prog.exe"}, {"--sates_output=\"xml:result.xml\""} };

int main(int argc, const char** argv)
{
    //sates::init(argc, argv);

    sates::init(2, custom_arg);
    sates::run_all_tests();
    sates::print_result();
    sates::terminate();
    return 0;
}
