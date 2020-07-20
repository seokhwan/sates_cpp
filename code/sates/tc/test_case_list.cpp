//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/tc/test_case_list.h>
#include <sates/common/err_proc.h>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <fstream>

namespace sates
{
namespace tc
{
typedef std::map<std::string, test_case*> code_map_t;
static std::shared_ptr<code_map_t> p_test_case_map = nullptr;
//static code_map_t test_case_map;
static std::vector<test_case*> runnable_tc_vec;

static std::vector<std::string> inc_list;
static std::vector<std::string> exc_list;

static void create()
{
	if (nullptr == p_test_case_map)
	{
		p_test_case_map.reset(new code_map_t);
	}
}

static bool is_in_the_list(const char* p_test_case_name, const std::vector<std::string>& tc_list)
{
	bool retval = false;
	std::string str_case_name = p_test_case_name;

	// new syntax
	for (auto item : tc_list)
	{
		if (item == str_case_name)
		{
			retval = true;
			break;
		}
	}
	return retval;
}

static bool is_in_inc_ext_list(const char* p_test_case_name)
{
	bool retval =
		(is_in_the_list(p_test_case_name, inc_list) &&
			is_in_the_list(p_test_case_name, exc_list));
	return retval;
}

void test_case_list::add_test_case(test_case* p_code)
{
	create();
	if (nullptr != p_code)
	{
		code_map_t::iterator iter = p_test_case_map->find(p_code->get_test_case_name());
		if (p_test_case_map->end() == iter)
		{
			p_test_case_map->emplace(p_code->get_test_case_name(), p_code);
			//test_case_map[p_code->get_test_case_name()] = p_code;
		}
		else
		{
			sates::common::err_proc("test_case_list::add_test_case(), Test Case Name Duplicated");
		}
	}
	else
	{
		sates::common::err_proc("test_case_list::add_test_case(), p_code is nullptr");
	}
	
}

test_case* test_case_list::get_test_case(const char* p_test_case_name)
{
	create();
	test_case* p_retval = nullptr;

	if (nullptr != p_test_case_name)
	{
		auto iter = p_test_case_map->find(p_test_case_name);
		if (p_test_case_map->end() != iter)
		{
			p_retval = iter->second;
		}
	}
	else
	{
		sates::common::err_proc("test_case_list::get_test_case(), p_test_case_name is nullptr");
	}
	
	return p_retval;
}

void test_case_list::include_test_case(const char* p_test_case_name)
{
	if (nullptr != p_test_case_name)
	{
		if (!is_in_inc_ext_list(p_test_case_name))
		{
			inc_list.push_back(p_test_case_name);
		}
	}
}

void test_case_list::exclude_test_case(const char* p_test_case_name)
{
	if (nullptr != p_test_case_name)
	{
		if (!is_in_inc_ext_list(p_test_case_name))
		{
			exc_list.push_back(p_test_case_name);
		}
	}
}

const std::vector<test_case*>* test_case_list::get_runnable_test_cases()
{
	create();
	runnable_tc_vec.clear();

	if (inc_list.size() > 0U)
	{
		for (auto iter : inc_list)
		{
			runnable_tc_vec.push_back(p_test_case_map->find(iter)->second);
		}
	}
	else if (exc_list.size() > 0U)
	{
		for (auto iter : (*p_test_case_map))
		{
			if (!is_in_the_list(iter.first.c_str(), exc_list))
			{
				runnable_tc_vec.push_back(iter.second);
			}
		}
	}
	else
	{
		for (auto iter : (*p_test_case_map))
		{
			runnable_tc_vec.push_back(iter.second);
		}
	}

	return &runnable_tc_vec;
}

}
}

