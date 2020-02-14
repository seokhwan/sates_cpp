//------------------------------------------------------------------------------
// Copyright (C) 2018, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates_test_cpp_deploy.h
//------------------------------------------------------------------------------

#ifndef __SATES_INTERNAL_USE_TESTCODE_H__
#define __SATES_INTERNAL_USE_TESTCODE_H__

#include <sates/define.h>
#include <vector>
#include <string>

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
class SATES_EXPORT testcode
{
public:
	testcode();
	virtual ~testcode();
	virtual void init();
	virtual void run();
	virtual void terminate();

	void set_result(TEST_RESULT test_result);
	void add_err_log(const std::string& err_msg);
	const std::vector<std::string>& get_err_log() const;
	TEST_RESULT get_result() const;

	const char_t* get_test_case_name() const;

	void print(const char* p_outfile);

protected:
	std::string m_test_case_name;
	std::vector<std::string> m_err_logs;
	TEST_RESULT m_result;
};
}
}

#endif // __SATES_INTERNAL_USE_TESTCODE_H__
