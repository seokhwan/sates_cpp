//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/sates.h>

int main(int argc, char** argv)
{
    sates::init();
    sates::run();
    sates::print_result(nullptr);
    sates::terminate();
    return 0;
}