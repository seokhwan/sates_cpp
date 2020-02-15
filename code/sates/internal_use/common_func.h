//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_INTERNAL_USE_COMMON_FUNC_H__
#define __SATES_INTERNAL_USE_COMMON_FUNC_H__

#include <sates/define.h>
#include <vector>
#include <string>

namespace sates
{
	namespace internal_use
	{
		bool is_in_the_list(const char* p_test_case_name, std::vector<std::string>* p_list);
	}
}

#endif // __SATES_INTERNAL_USE_COMMON_FUNC_H__

