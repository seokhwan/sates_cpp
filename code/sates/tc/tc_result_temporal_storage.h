//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_TC_RESULT_TEMPORAL_STORAGE_H__
#define __SATES_TC_RESULT_TEMPORAL_STORAGE_H__

#include <sates/tc/tc_result.h>

namespace sates
{
	namespace tc
	{
		class tc_result_temporal_storage
		{
		public:
			static void clear_prev_result();
			static void add_error(const std::string& error_message);
			static bool is_err_occurred();
			static std::vector<std::string>* get_accumulated_logs();

		};
	}
}

#endif // __SATES_TC_RESULT_TEMPORAL_STORAGE_H__

