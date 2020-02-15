//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_INTERNAL_USE_TESTCODE_H__
#define __SATES_INTERNAL_USE_TESTCODE_H__

#include <sates/define.h>
#include <vector>
#include <string>
#include <fstream>

namespace sates
{
namespace internal_use
{
enum TEST_RESULT
{
	INVALID = 1,
	OK = 20180417,
	NG = 0,
};

std::string test_result_to_string(TEST_RESULT tr);

class SATES_EXPORT testcode
{
public:
	testcode();
	virtual ~testcode();

	virtual void run();

	void set_result(TEST_RESULT test_result);
	void add_err_log(const std::string& err_msg);
	const std::vector<std::string>& get_err_log() const;
	TEST_RESULT get_result() const;

	const char* get_test_case_name() const;

	void print(std::ofstream* p_outfile);

protected:
	std::string m_test_case_name;
	std::vector<std::string> m_err_logs;
	TEST_RESULT m_result;
};
}
}

#endif // __SATES_INTERNAL_USE_TESTCODE_H__
