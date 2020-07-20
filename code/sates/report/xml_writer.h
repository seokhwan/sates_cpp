//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_REPORT_XML_WRITER_H__
#define __SATES_REPORT_XML_WRITER_H__

#include <sates/report/writer.h>

namespace sates
{
namespace report
{

class SATES_EXPORT xml_writer : public writer
{
public:
	xml_writer();
	virtual ~xml_writer();
	virtual const std::string& gen_one_case_report(const sates::tc::tc_result& result);
	virtual const std::string& gen_full_report();
	virtual const std::string& gen_summary();
};

}
}

#endif // __SATES_REPORT_XML_WRITER_H__
