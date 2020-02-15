//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_INTERNAL_USE_TEST_RUNNER_H__
#define __SATES_INTERNAL_USE_TEST_RUNNER_H__

#include <sates/internal_use/testcode.h>
#include <vector>
#include <string>
#include <map>

namespace sates
{
	namespace internal_use
	{
		class test_runner
		{
		public:
            static TEST_RESULT run(std::vector<std::string>* p_inc_list,
                std::vector<std::string>* p_exc_list,
				std::map<std::string, testcode*>* p_map);
		};
	}
}

#endif // __SATES_INTERNAL_USE_TEST_RUNNER_H__

