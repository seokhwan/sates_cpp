//------------------------------------------------------------------------------
// Copyright (C) 2018, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates_test_cpp_deploy.h
//------------------------------------------------------------------------------

#include <sates/internal_use/testcode.h>
#include <iostream>
#include <cstring>

namespace sates
{
namespace internal_use
{
testcode::testcode()
{
	m_test_case_name = "";
	m_result = TEST_RESULT::INVALID;
}

testcode::~testcode() {}
void testcode::init() {}
void testcode::run() {}
void testcode::terminate() {}

void testcode::set_result(TEST_RESULT test_result)
{
	m_result = test_result;
}

void testcode::add_err_log(const std::string& err_msg)
{
	m_err_logs.push_back(err_msg);
}

const std::vector<std::string>& testcode::get_err_log() const
{
	return m_err_logs;
}

TEST_RESULT testcode::get_result() const
{
	return m_result;
}

const char_t* testcode::get_test_case_name() const
{
	return m_test_case_name.c_str();
}

void testcode::print(const char* p_outfile)
{
	std::vector<std::string> result_str;
	result_str.push_back("\n");
	result_str.push_back("\n");
	
	result_str.push_back("################################################################################\n");
	result_str.push_back("Test Case Name : " + m_test_case_name + "\n");
	result_str.push_back("################################################################################\n");
	
	result_str.push_back("Test Result : \n");
	if (TEST_RESULT::OK == m_result)
	{
		result_str.push_back("OK\n");
	}
	else if (TEST_RESULT::NG == m_result)
	{
		result_str.push_back("NG\n");
	}
	else
	{
		result_str.push_back("Not Tested\n");
	}
	if (TEST_RESULT::NG == m_result)
	{
		result_str.push_back("================================================================================\n");
		result_str.push_back("Failure Info : \n");
		for (auto iter : m_err_logs)
		{
			result_str.push_back(iter + "\n");
		}
	}
	result_str.push_back("================================================================================\n");

	result_str.push_back("\n");
	result_str.push_back("\n");

	if (nullptr == p_outfile)
	{
		for (auto str : result_str)
		{
			std::cout << str;
		}
	}
}
}
}

