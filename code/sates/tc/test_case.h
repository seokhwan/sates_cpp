//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_TC_TEST_CASE_H__
#define __SATES_TC_TEST_CASE_H__

#include <sates/define.h>
#include <vector>
#include <string>
#include <fstream>

namespace sates
{
namespace tc
{

class SATES_EXPORT test_case
{
public:
	test_case();
	virtual ~test_case();

	virtual void run();

	const char* get_test_case_name() const;


protected:
	std::string m_test_case_name;
};
}
}

#endif // __SATES_TC_TEST_CASE_H__
