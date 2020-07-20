//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_REPORT_PLAIN_TEXT_STD_OUT_H__
#define __SATES_REPORT_PLAIN_TEXT_STD_OUT_H__

#include <sates/report/writer.h>

namespace sates
{
namespace report
{
class SATES_EXPORT plain_text_stdout
{
public:
	static const std::vector<std::string>& gen_one_case_report(const sates::tc::tc_result& result);
	static const std::vector<std::string>& gen_full_report();
	static const std::vector<std::string>& gen_summary();
};
}
}

#endif // __SATES_REPORT_PLAIN_TEXT_STD_OUT_H__
