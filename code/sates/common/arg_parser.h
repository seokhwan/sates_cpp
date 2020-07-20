//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_COMMON_ARG_PARSER_H__
#define __SATES_COMMON_ARG_PARSER_H__

#include <sates/define.h>
#include <vector>
#include <string>

namespace sates
{
namespace common
{
class SATES_EXPORT arg_parser
{
public:
	static void parse(int argc, const char** argv);
	static void get_arg(const std::string& str_option, std::vector<std::string>& vec);
};
}
}

#endif // __SATES_COMMON_ARG_PARSER_H__

