//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include "tc_result_temporal_storage.h"

namespace sates
{
	namespace tc
	{
		static int32_t error_count = 0;
		static std::vector<std::string> err_logs;
		void tc_result_temporal_storage::clear_prev_result()
		{
			error_count = 0;
			err_logs.clear();
		}

		void tc_result_temporal_storage::add_error(const std::string& error_message)
		{
			error_count++;
			err_logs.push_back(error_message);
		}

		bool tc_result_temporal_storage::is_err_occurred()
		{
			return (error_count > 0);
		}

		std::vector<std::string>* tc_result_temporal_storage::get_accumulated_logs()
		{
			return &err_logs;
		}
	}
}