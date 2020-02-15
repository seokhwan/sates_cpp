//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_INTERNAL_USE_TEST_LIST_EDITOR_H__
#define __SATES_INTERNAL_USE_TEST_LIST_EDITOR_H__

#include <sates/define.h>
#include <vector>
#include <string>

namespace sates
{
	namespace internal_use
	{
		class test_list_editor
		{
		public:
			static void create();
			static void destroy();

			static void include_test(const char* p_test_case_name);
			static void exclude_test(const char* p_test_case_name);

			static std::vector<std::string>* get_include_list();
			static std::vector<std::string>* get_exclude_list();
		};
	}
}

#endif // __SATES_INTERNAL_USE_TEST_LIST_EDITOR_H__

