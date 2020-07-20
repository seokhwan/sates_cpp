//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/sates_test_cpp_deploy.h>
#include <sates/tc/test_case_list.h>
#include <sates/common/arg_parser.h>
#include <sates/report/writer_factory.h>
#include <sates/tester/tc_run.h>

#include <fstream>

namespace sates
{
    void enable(const char* p_test_name)
    {
        sates::tc::test_case_list::include_test_case(p_test_name);
    }
    void disable(const char* p_test_name)
    {
        sates::tc::test_case_list::exclude_test_case(p_test_name);
    }
    void init(int argc, const char** argv)
    {
        sates::common::arg_parser::parse(argc, argv);
    }
    void run_all_tests()
    {
        sates::tester::tc_runner::run();
    }
    void terminate()
    {
    }
    void print_result()
    {
        std::vector<std::string> opt;
        sates::common::arg_parser::get_arg("sates_output", opt);
        if (opt.size() == 2U)
        {
            auto p_writer = sates::report::writer_factory::create(opt[0].c_str());
            auto str_report = p_writer->gen_full_report();

            std::ofstream of;
            of.open(opt[1]);
            of << str_report;
            of.close();

        }
    }
}

