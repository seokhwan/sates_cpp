//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/sates.h>

SATES_TEST_RUN(TC_OK)
{
    SATES_EQ(1, 1);
    SATES_EQ(2, 2);
    SATES_EQ(3, 3);
    SATES_EQ(4, 4);
}


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

SATES_TEST_RUN(TC_NG_03)
{
    SATES_EQ(0, 1);
    SATES_NE(1, 1);
    SATES_TRUE(false);
}
