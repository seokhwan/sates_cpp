//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_TEST_CPP_DEPLOY_H__
#define __SATES_TEST_CPP_DEPLOY_H__

#ifdef SATES_NO_DEPLOY
    #include <sates/internal_use/test_macro.h>
	namespace sates
	{
		SATES_EXPORT void include_list(const char* p_test_name);
		SATES_EXPORT void exclude_list(const char* p_test_name);
		SATES_EXPORT void init();
		SATES_EXPORT void run();
		SATES_EXPORT void terminate();
		SATES_EXPORT void print_result(const char* p_outfile);
		SATES_EXPORT void set_float_eq_threshold(float val);
		SATES_EXPORT void set_double_eq_threshold(double val);

		SATES_EXPORT float get_float_eq_threshold();
		SATES_EXPORT double get_double_eq_threshold();
	}
#endif 

#ifdef __cplusplus
extern "C" {
#endif

	void _sates_test_help_eval_impl(bool expr, int line, const char* p_file_name);
	void _sates_test_help_eval_impl_eq_float(float val1, float val2, int line, const char* p_file_name);
	void _sates_test_help_eval_impl_ne_float(float val1, float val2, int line, const char* p_file_name);
	void _sates_test_help_eval_impl_eq_double(double val1, double val2, int line, const char* p_file_name);
	void _sates_test_help_eval_impl_ne_double(double val1, double val2, int line, const char* p_file_name);

	

#define SATES_TRUE(val) \
    _sates_test_help_eval_impl((val), __LINE__, __FILE__)

#define SATES_FALSE(val) \
    _sates_test_help_eval_impl(!(val), __LINE__, __FILE__)

#define SATES_EQ(val1, val2) \
    _sates_test_help_eval_impl(((val1) == (val2)), __LINE__, __FILE__)

#define SATES_NE(val1, val2) \
    _sates_test_help_eval_impl(((val1) != (val2)), __LINE__, __FILE__)

#define SATES_FLOAT_EQ(val1, val2) \
    _sates_test_help_eval_impl_eq_float((val1), (val2), __LINE__, __FILE__)

#define SATES_FLOAT_NE(val1, val2) \
    _sates_test_help_eval_impl_ne_float((val1), (val2), __LINE__, __FILE__)

#define SATES_DOUBLE_EQ(val1, val2) \
    _sates_test_help_eval_impl_eq_double((val1), (val2), __LINE__, __FILE__)

#define SATES_DOUBLE_NE(val1, val2) \
    _sates_test_help_eval_impl_ne_double((val1), (val2), __LINE__, __FILE__)

	void _sates_no_framework_start(const char* p_testcase_name);
	void _staes_no_framework_terminate(const char* p_testcase_name);

#ifndef SATES_TEST_RUN
#define SATES_TEST_RUN(TEST_CASE_NAME) void sates_test_run##TEST_CASE_NAME()
#endif


#define SATES_TEST_RUN_MAIN_FUNC_RUN(TEST_CASE_NAME) \
	extern void sates_test_run##TEST_CASE_NAME(); \
	_sates_no_framework_start(#TEST_CASE_NAME);\
	sates_test_run##TEST_CASE_NAME(); \
	_staes_no_framework_terminate(#TEST_CASE_NAME);

#ifdef __cplusplus
}
#endif


#endif // __SATES_TEST_CPP_DEPLOY_H__
