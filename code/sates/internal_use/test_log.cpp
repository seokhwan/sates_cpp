//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/internal_use/test_log.h>

namespace sates
{
	namespace internal_use
	{
		static int32_t error_count = 0;
		static std::vector<std::string> err_logs;
		void test_log::start_new_test()
		{
			error_count = 0;
			err_logs.clear();
		}

		void test_log::error(const std::string& error_message)
		{
			error_count++;
			err_logs.push_back(error_message);
		}

		bool test_log::is_err_occurred()
		{
			return (error_count > 0);
		}

		std::vector<std::string>* test_log::get_accumulated_logs()
		{
			return &err_logs;
		}
	}
}


