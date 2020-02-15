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

#ifdef SATES_NO_DEPLOY
#include <sates/internal_use/stdout_color.h>
#include <sates/internal_use/test_log.h>
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
		std::string err_str = "TEST FAILURE, line : ";
		err_str += std::to_string(line);
		err_str += ", file : ";
		err_str += p_file_name;

		++tc_err_cnt;

#ifdef SATES_NO_DEPLOY
		sates::internal_use::test_log::error(err_str);
#endif
		
#ifdef SATES_NO_DEPLOY
		sates::internal_use::set_stdout_color(sates::internal_use::CONSOLE_COLOR::CONSOLE_COLOR_WHITE,
			sates::internal_use::CONSOLE_COLOR::CONSOLE_COLOR_BLUE);
		std::cout << sates::internal_use::get_stdout_color()
#else
		std::cout
#endif
			<< err_str << std::endl;

#ifdef SATES_NO_DEPLOY
		sates::internal_use::clear_stdout_color();
		sates::internal_use::set_stdout_color(sates::internal_use::CONSOLE_COLOR::CONSOLE_COLOR_WHITE,
			sates::internal_use::CONSOLE_COLOR::CONSOLE_COLOR_BLACK);
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

