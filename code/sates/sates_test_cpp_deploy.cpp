//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/sates_test_cpp_deploy.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#ifdef SATES_WIN
	#include <Windows.h>
#endif

#ifdef SATES_LINUX
	#include <stdlib.h>
#endif

#ifdef SATES_NO_DEPLOY
#include <sates/tc/tc_result_temporal_storage.h>
#endif

static float _sates_test_help_float_eq = 1E-10F;
static double _sates_test_help_double_eq = 1E-10;

static uint32_t tc_err_cnt = 0U;
static uint32_t num_of_tc = 0U;

namespace sates
{
	void set_float_eq_threshold(float val)
	{
		_sates_test_help_float_eq = val;
	}

	void set_double_eq_threshold(double val)
	{
		_sates_test_help_double_eq = val;
	}

	float get_float_eq_threshold()
	{
		return _sates_test_help_float_eq;
	}

	double get_double_eq_threshold()
	{
		return _sates_test_help_double_eq;
	}


	int64_t process_run(const char* p_cmd_line, uint32_t cmd_line_len)
	{
#ifdef SATES_WIN
		static const uint32_t CMD_LINE_SIZE = 1024U;
		char cmd_line[1024];
		std::memset(cmd_line, 0, CMD_LINE_SIZE);
		uint32_t i = 0U;
		while (i < cmd_line_len)
		{
			cmd_line[i] = p_cmd_line[i];
			i++;
		}

		STARTUPINFOA si;
		PROCESS_INFORMATION pi;

		std::memset(&si, 0, sizeof(si));
		si.cb = sizeof(si);
		std::memset(&pi, 0, sizeof(pi));

		CreateProcessA(NULL,   // No module name (use command line)
			cmd_line,
			NULL,           // Process handle not inheritable
			NULL,           // Thread handle not inheritable
			FALSE,          // Set handle inheritance to FALSE
			CREATE_NEW_CONSOLE,
			NULL,           // Use parent's environment block
			NULL,           // Use parent's starting directory 
			&si,            // Pointer to STARTUPINFO structure
			&pi);           // Pointer to PROCESS_INFORMATION structure
		return reinterpret_cast<int64_t>(pi.hProcess);
#elif defined(SATES_LINUX)
		return static_cast<int64_t>(::system(p_cmd_line));
#else
		return 0;
#endif
	}

	int64_t process_kill(int64_t process_id)
	{
#ifdef SATES_WIN
		int64_t retval = 0;
		auto result = TerminateProcess(reinterpret_cast<HANDLE>(process_id), 0U);
		if (!result)
		{
			retval = -1;
		}
		return retval;
#elif defined(SATES_LINUX)
		return 0;
#else
		return 0;
#endif
	}
}

static float _sates_test_help_abs(float val)
{
	if (val < 0.0F)
	{
		val = val * -1.0F;
	}
	return val;
}

static double _sates_test_help_abs(double val)
{
	if (val < 0.0)
	{
		val = val * -1.0;
	}
	return val;
}

void _sates_test_help_eval_impl(bool expr, int line, const char* p_file_name)
{
	num_of_tc++;
	if (!(expr))
	{
		std::string err_str = p_file_name;
		err_str += ":" + std::to_string(line);
		++tc_err_cnt;

#ifndef SATES_NO_DEPLOY
		std::cout << err_str << std::endl;
#else
		sates::tc::tc_result_temporal_storage::add_error(err_str);
#endif
	}
}

void _sates_test_help_eval_impl_eq_float(float val1, float val2, int line, const char* p_file_name)
{
	_sates_test_help_eval_impl(
		(_sates_test_help_abs(val1 - val2) <= _sates_test_help_float_eq),
		line,
		p_file_name);
}

void _sates_test_help_eval_impl_ne_float(float val1, float val2, int line, const char* p_file_name)
{
	_sates_test_help_eval_impl(
		(_sates_test_help_abs(val1 - val2) > _sates_test_help_float_eq),
		line,
		p_file_name);
}

void _sates_test_help_eval_impl_eq_double(double val1, double val2, int line, const char* p_file_name)
{
	_sates_test_help_eval_impl(
		(_sates_test_help_abs(val1 - val2) <= _sates_test_help_double_eq),
		line,
		p_file_name);
}

void _sates_test_help_eval_impl_ne_double(double val1, double val2, int line, const char* p_file_name)
{
	_sates_test_help_eval_impl(
		(_sates_test_help_abs(val1 - val2) > _sates_test_help_double_eq),
		line,
		p_file_name);
}

void _sates_no_framework_start(const char* p_testcase_name)
{
	num_of_tc = 0U;
	tc_err_cnt = 0U;
}

void _staes_no_framework_terminate(const char* p_testcase_name)
{
	std::cout << "=== Test Case : " << p_testcase_name << ", # of Test Cases : "<< num_of_tc << ", Result : ";
	if (0U == tc_err_cnt)
	{
		std::cout << "SUCCESS" << std::endl;
	}
	else
	{
		std::cout << "FAIL" << std::endl;
	}
}

