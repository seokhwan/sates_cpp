//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include "tc_result.h"
#include <chrono>
#include <iomanip>
#include <sstream>

namespace sates
{
namespace tc
{
tc_result::tc_result(const char* test_name)
{
			
	test_case_name = test_name;
	init();
}
		
tc_result::tc_result(const std::string& test_name)
{
	test_case_name = test_name;
	init();
}

tc_result::~tc_result() {}
		
void tc_result::mark_tc_started()
{
	time_begin = std::chrono::system_clock::now();
}

void tc_result::mark_tc_completed()
{
	time_end = std::chrono::system_clock::now();
}

void tc_result::add_failure(const char* p_failure_msg)
{
	std::string failure_msg = p_failure_msg;
	this->add_failure(failure_msg);
}

void tc_result::add_failure(const std::string& failure_msg)
{
	failures++;
	test_ok_ng = "NG";
	failure_log.push_back(failure_msg);
}

std::string tc_result::get_time_stamp() const
{
	std::ostringstream oss;
	auto time_val = std::chrono::system_clock::to_time_t(time_begin);
	oss << std::put_time(std::localtime(&time_val), "%Y-%m-%dT%H:%M:%S");
	return oss.str();
}
float tc_result::get_taken_time_ms() const
{
	float mic_time = static_cast<float>(std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_begin).count());
	mic_time = mic_time / 1000.F / 1000.F;
	return mic_time;
}


void tc_result::init()
{
	failures = 0U;
	disabled = 0U;
	errors = 0U;
	test_ok_ng = "OK";
}
}
}


