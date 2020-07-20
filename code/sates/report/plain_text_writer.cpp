#include "plain_text_writer.h"
#include "plain_text_stdout.h"
#include <sates/tc/tc_result_list.h>
#include <sstream>
#include <iomanip>

namespace sates
{
namespace report
{

plain_text_writer::plain_text_writer() {}

plain_text_writer::~plain_text_writer() {}

const std::string& plain_text_writer::gen_one_case_report(const sates::tc::tc_result& result)
{
    m_str.clear();
    auto vec = plain_text_stdout::gen_one_case_report(result);
    for (auto line : vec)
    {
        m_str += line;
    }
    //

    //m_str = "################################################################################\n";
    //m_str += "Test Case Name : " + result.test_case_name + "\n";
    //m_str += "Test Result    : " + result.test_ok_ng + "\n";
    ////m_str += "Disabled       : " + std::to_string(result.disabled) + "\n";
    //m_str += "Time Stamp     : " + result.get_time_stamp() + "\n";
    //m_str += "Taken Time     : " + std::to_string(result.get_taken_time_ms()) + "\n";
    ////m_str += "Failure #001   : " + std::to_string(result.failures) + "\n";
    //for (uint32_t i = 0U; i < result.failures; i++)
    //{
    //    std::ostringstream oss;
    //    oss << std::setw(3) << std::setfill('0') << (i + 1U);
    //    m_str += "Failure #" + oss.str() + "   : ";
    //    m_str += result.failure_log.at(i) + "\n";
    //}
    //m_str += "################################################################################\n\n";

    return m_str;
}

const std::string& plain_text_writer::gen_full_report()
{
    m_full_str.clear();
    auto vec = plain_text_stdout::gen_full_report();
    for (auto line : vec)
    {
        m_full_str += line;
    }
    return m_full_str;
}

const std::string& plain_text_writer::gen_summary()
{
    m_summary_str.clear();
    auto vec = plain_text_stdout::gen_summary();
    for (auto line : vec)
    {
        m_summary_str += line;
    }
    return m_summary_str;


    /*auto p_tc_list = tc::tc_result_list::get_instance();
    m_summary_str.clear();
    m_summary_str = "################################################################################\n";
    m_summary_str += "SUMMARY \n";
    m_summary_str += "RESULT         : " + p_tc_list->test_ok_ng + "\n";
    m_summary_str += "TOTAL FAILURES : " + std::to_string(p_tc_list->get_total_num_of_failures()) + "\n";
    m_summary_str += "TIME STAMP     : " + p_tc_list->get_time_stamp() + "\n";
    m_summary_str += "TOTAL TIME     : " + std::to_string(p_tc_list->get_total_taken_time()) + "\n";
    m_summary_str += "################################################################################\n";

    return m_summary_str;*/
}

}
}

