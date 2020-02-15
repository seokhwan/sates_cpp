//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_TESTCODE_INTERNAL_USE_LIST_H__
#define __SATES_TESTCODE_INTERNAL_USE_LIST_H__

#include <sates/internal_use/testcode.h>
#include <vector>

namespace sates
{
namespace internal_use
{
class SATES_EXPORT testcode_list
{
public:
	static void create();
	static void destroy();
	static void add_testcode(testcode* p_code);
	static testcode* get_testcode(const char* p_test_case_name);

	static void include_testcode(const char* p_test_case_name);
	static void exclude_testcode(const char* p_test_case_name);

	static void run();
	static void print_result(const char* p_outfile);
};
}
}

#endif // __SATES_TESTCODE_INTERNAL_USE_LIST_H__

