#include "plain_text_stdout.h"
#include <sates/tc/tc_result_list.h>
#include <sstream>
#include <iomanip>

namespace sates
{
namespace report
{

static std::vector<std::string> m_strvec;
static std::vector<std::string> m_fullvec;;
static std::vector<std::string> m_summaryvec;


const std::vector<std::string>& plain_text_stdout::gen_one_case_report(const sates::tc::tc_result& result)
{
    m_strvec.clear();
    

    m_strvec.push_back("################################################################################\n");
    m_strvec.push_back("Test Case Name : " + result.test_case_name + "\n");
    m_strvec.push_back("Test Result    : " + result.test_ok_ng + "\n");
    m_strvec.push_back("Time Stamp     : " + result.get_time_stamp() + "\n");
    m_strvec.push_back("Taken Time     : " + std::to_string(result.get_taken_time_ms()) + "\n");
    for (uint32_t i = 0U; i < result.failures; i++)
    {
        std::ostringstream oss;
        oss << std::setw(3) << std::setfill('0') << (i + 1U);
        std::string str = "Failure #" + oss.str() + "   : ";
        str += result.failure_log.at(i) + "\n";
        m_strvec.push_back(str);
    }
    m_strvec.push_back("################################################################################\n\n");

    return m_strvec;
}

const std::vector<std::string>& plain_text_stdout::gen_full_report()
{
    m_fullvec.clear();
    return m_fullvec;
}

const std::vector<std::string>& plain_text_stdout::gen_summary()
{
    m_summaryvec.clear();
    auto p_tc_list = tc::tc_result_list::get_instance();
    
    m_summaryvec.push_back("################################################################################\n");
    m_summaryvec.push_back("SUMMARY \n");
    m_summaryvec.push_back("RESULT         : " + p_tc_list->test_ok_ng + "\n");
    m_summaryvec.push_back("TOTAL FAILURES : " + std::to_string(p_tc_list->get_total_num_of_failures()) + "\n");
    m_summaryvec.push_back("TIME STAMP     : " + p_tc_list->get_time_stamp() + "\n");
    m_summaryvec.push_back("TOTAL TIME     : " + std::to_string(p_tc_list->get_total_taken_time()) + "\n");
    m_summaryvec.push_back("################################################################################\n");

    return m_summaryvec;
}

}
}

