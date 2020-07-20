//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/tc/test_case.h>
#include <iostream>
#include <cstring>

namespace sates
{
namespace tc
{

test_case::test_case()
{
	m_test_case_name = "";
}

test_case::~test_case() { }

void test_case::run() {}

const char* test_case::get_test_case_name() const
{
	return m_test_case_name.c_str();
}

}
}

