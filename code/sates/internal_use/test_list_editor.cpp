//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/internal_use/test_list_editor.h>
#include <sates/internal_use/common_func.h>
#include <sates/internal_use/testcode_list.h>
#include <vector>

namespace sates
{

namespace internal_use 
{

static std::vector<std::string>* p_included_list = nullptr;
static std::vector<std::string>* p_excluded_list = nullptr;



static bool is_in_inc_ext_list(const char* p_test_case_name)
{
	bool retval =
		(is_in_the_list(p_test_case_name, p_included_list) &&
		 is_in_the_list(p_test_case_name, p_excluded_list));
	return retval;
}

void test_list_editor::create()
{
	static bool is_created = false;
	if (!is_created)
	{
		is_created = true;
		p_included_list = new std::vector<std::string>();
		p_excluded_list = new std::vector<std::string>();
	}
}

void test_list_editor::destroy()
{
	SATES_SAFE_DELETE(p_included_list);
	SATES_SAFE_DELETE(p_excluded_list);
}

void test_list_editor::include_test(const char* p_test_case_name)
{
	test_list_editor::create();
	
	if (nullptr != p_test_case_name)
	{
		if (!is_in_inc_ext_list(p_test_case_name))
		{
			p_included_list->push_back(p_test_case_name);
		}
	}
}

void test_list_editor::exclude_test(const char* p_test_case_name)
{
	test_list_editor::create();

	if (nullptr != p_test_case_name)
	{
		if (!is_in_inc_ext_list(p_test_case_name))
		{
			p_excluded_list->push_back(p_test_case_name);
		}
	}
}

std::vector<std::string>* test_list_editor::get_include_list()
{
	test_list_editor::create();
	return p_included_list;
}

std::vector<std::string>* test_list_editor::get_exclude_list()
{
	test_list_editor::create();
	return p_excluded_list;
}

}
}
