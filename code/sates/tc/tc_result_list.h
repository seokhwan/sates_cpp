//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_TC_RESULT_LIST_H__
#define __SATES_TC_RESULT_LIST_H__

#include <sates/tc/tc_result.h>

namespace sates
{
	namespace tc
	{
		class SATES_EXPORT tc_result_list : public tc_result
		{
		public:
			~tc_result_list();
			static tc_result_list* get_instance();
			void add_result(const tc_result& result);
			uint32_t get_total_num_of_failures();
			uint32_t get_total_num_of_failure_test_cases();
			float get_total_taken_time();

			uint32_t get_num_of_tc();

			const std::vector<tc_result>* get_list() const;
			

		protected:
			tc_result_list();
		};
	}
}

#endif // __SATES_TC_RESULT_LIST_H__

