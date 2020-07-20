//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_COMMON_ARG_SATES_OUTPUT_H__
#define __SATES_COMMON_ARG_SATES_OUTPUT_H__

#include <sates/define.h>
#include <string>
#include <map>
#include <vector>

namespace sates
{
	namespace common
	{
		class SATES_EXPORT arg_sates_output
		{
		public:
			static void fill_data(std::map<std::string, std::vector<std::string>>& data_map,const std::string& str_data);
			static const std::string str_option;
		};
	}
}

#endif // __SATES_COMMON_ARG_SATES_OUTPUT_H__

