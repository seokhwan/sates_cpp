//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_REPORT_WRITER_H__
#define __SATES_REPORT_WRITER_H__

#include <sates/tc/tc_result.h>

namespace sates
{
namespace report
{
class SATES_EXPORT writer
{
public:
	writer();
	virtual ~writer();
	virtual const std::string& gen_one_case_report(const sates::tc::tc_result& result);
	virtual const std::string& gen_full_report();
	virtual const std::string& gen_summary();

protected:
	std::string m_str;
	std::string m_full_str;
	std::string m_summary_str;
};
}
}

#endif // __SATES_REPORT_WRITER_H__
