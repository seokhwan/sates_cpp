#include "xml_writer.h"
#include <sates/tc/tc_result_list.h>

namespace sates
{
namespace report
{
xml_writer::xml_writer() {}

xml_writer::~xml_writer() {}

const std::string& xml_writer::gen_one_case_report(const tc::tc_result& result)
{
    m_str.clear();
    //<testcase classname = "TEST00" name = "test_00" status = "run" result = "completed" time = "0.001" timestamp = "2020-07-13T11:12:22" >
    m_str += "  <testcase classname=\"" + result.test_case_name + "\" name=\"()\" ";
    m_str += "status=\"run\" result=\"completed\" ";
    m_str += "time=\"" + std::to_string(result.get_taken_time_ms()) + "\" ";
    m_str += "timestamp=\"" + result.get_time_stamp() + "\">\n";

    for (uint32_t i = 0U; i < result.failures; i++)
    {
        m_str += "    <failure message=\"" + result.failure_log.at(i) + "\" type=\"\">\n";
        m_str += "    <![CDATA[" + result.failure_log.at(i) + "]]>\n";
        m_str += "    </failure>\n";
    }
    m_str += "  </testcase>\n";
    return m_str;
}

const std::string& xml_writer::gen_full_report()
{
    // <testsuites tests="3" failures="2" disabled="0" errors="0" time="0.021" timestamp="2020-07-13T11:12:22" name="AllTests">
    auto p_tc_list = tc::tc_result_list::get_instance();
    m_full_str.clear();
    m_full_str += "<testsuites tests=\"" + std::to_string(p_tc_list->get_num_of_tc()) + "\" ";
    m_full_str += "failures=\"" + std::to_string(p_tc_list->get_total_num_of_failure_test_cases()) + "\" ";
    m_full_str += "time=\"" + std::to_string(p_tc_list->get_total_taken_time()) + "\" ";
    m_full_str += "timestamp=\"" + p_tc_list->get_time_stamp() + "\" ";
    m_full_str += "disabled=\"0\" errors=\"0\" name=\"AllTests\">\n";

    for (auto item : *(p_tc_list->get_list()))
    {
        m_full_str += gen_one_case_report(item);
    }
    m_full_str += "</testsuites>\n";

    //m_full_str = "################################################################################\n";
    //m_full_str += "SUMMARY \n";
    //m_full_str += "RESULT         : " + internal_use::test_result_manager::result.test_ok_ng + "\n";
    //m_full_str += "TOTAL FAILURES : " + std::to_string(test_result_manager::get_total_num_of_failures()) + "\n";
    //m_full_str += "TIME STAMP     : " + internal_use::test_result_manager::result.get_time_stamp() + "\n";
    //m_full_str += "TOTAL TIME     : " + std::to_string(test_result_manager::get_total_taken_time()) + " ms\n";
    //m_full_str += "################################################################################\n";
    return m_full_str;
}

const std::string& xml_writer::gen_summary()
{
    return m_summary_str;
}

}
}
