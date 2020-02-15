//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/sates_test_cpp_deploy.h>
#include <sates/internal_use/testcode_list.h>
namespace sates
{
    void include_list(const char* p_test_name)
    {
        sates::internal_use::testcode_list::include_testcode(p_test_name);
    }
    void exclude_list(const char* p_test_name)
    {
        sates::internal_use::testcode_list::exclude_testcode(p_test_name);
    }
    void init()
    {
        sates::internal_use::testcode_list::create();
    }
    void run()
    {
        sates::internal_use::testcode_list::run();
    }
    void terminate()
    {
        sates::internal_use::testcode_list::destroy();
    }
    void print_result(const char* p_outfile)
    {
        sates::internal_use::testcode_list::print_result(p_outfile);
    }
}
