//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/sates.h>


SATES_TEST_RUN(T1)
{
    SATES_EQ(0, 1);
}


SATES_TEST_RUN(T2)
{
    SATES_EQ(0, 1);
}

SATES_TEST_RUN(T3)
{
    SATES_EQ(0, 0);
}


int main(int argc, char** argv)
{
    sates::init();
    sates::run();
    sates::print_result(nullptr);
    sates::terminate();
    return 0;
}
