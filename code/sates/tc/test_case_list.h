//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_TC_TEST_CASE_LIST_H__
#define __SATES_TC_TEST_CASE_LIST_H__

#include <sates/tc/test_case.h>
#include <vector>

namespace sates
{
namespace tc
{
class SATES_EXPORT test_case_list
{
public:
	static void add_test_case(test_case* p_code);
	static test_case* get_test_case(const char* p_test_case_name);
	static void include_test_case(const char* p_test_case_name);
	static void exclude_test_case(const char* p_test_case_name);

	static const std::vector<test_case*>* get_runnable_test_cases();

};
}
}

#endif // __SATES_TC_TEST_CASE_LIST_H__

