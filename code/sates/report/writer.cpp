#include "writer.h"

namespace sates
{
namespace report
{
writer::writer() {}
writer::~writer() {}
const std::string& writer::gen_one_case_report(const sates::tc::tc_result& result)
{
	return m_str;
}
const std::string& writer::gen_full_report()
{
	return m_str;
}

const std::string& writer::gen_summary()
{
	return m_summary_str;
}
}
}

