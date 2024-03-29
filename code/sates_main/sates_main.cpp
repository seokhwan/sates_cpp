//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/sates.h>

int main(int argc, const char** argv)
{
    sates::init(argc, argv);
    sates::run_all_tests ();
    sates::print_result();
    sates::terminate();
    return 0;
}