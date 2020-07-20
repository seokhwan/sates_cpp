//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_TC_RESULT_H__
#define __SATES_TC_RESULT_H__

#include <sates/define.h>
#include <vector>
#include <string>
#include <chrono>

namespace sates
{
namespace tc
{
	enum class TEST_RESULT
	{
		INVALID = 1,
		OK = 20180417,
		NG = 0,
	};

	class SATES_EXPORT tc_result
	{
	public:
		tc_result(const char* test_name);
		tc_result(const std::string& test_name);
		~tc_result();

		void mark_tc_started();
		void mark_tc_completed();

		void add_failure(const char* p_failure_msg);
		void add_failure(const std::string& failure_msg);

		std::string get_time_stamp() const;
		float get_taken_time_ms() const;

		uint32_t failures;
		uint32_t disabled;
		uint32_t errors;
		std::string test_case_name;
		std::string test_ok_ng;
		std::vector<std::string> failure_log;

	protected:
		void init();
			

	protected:
			

		std::chrono::system_clock::time_point time_begin;
		std::chrono::system_clock::time_point time_end;
			
	};
}
}

#endif // __SATES_TC_RESULT_H__

