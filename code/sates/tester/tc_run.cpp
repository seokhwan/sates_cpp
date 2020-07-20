//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include "tc_run.h"
#include <sates/tc/test_case_list.h>
#include <sates/tc/tc_result_list.h>
#include <sates/report/plain_text_stdout.h>
#include <sates/tc/tc_result_temporal_storage.h>
#include <sates/common/stdout_color.h>
#include <iostream>
#include <algorithm>

namespace sates
{
	namespace tester
	{
		//static auto p_writer = sates::report::writer_factory::create("plain");

		static void run_one_test_case(tc::test_case* p_code)
		{
			tc::tc_result_temporal_storage::clear_prev_result();
			tc::tc_result result(p_code->get_test_case_name());
			result.mark_tc_started();
			p_code->run();
			result.mark_tc_completed();
			
			if (tc::tc_result_temporal_storage::is_err_occurred())
			{
				for (auto iter : (*(tc::tc_result_temporal_storage::get_accumulated_logs())))
				{
					result.add_failure(iter);
				}
			}
			auto vec = report::plain_text_stdout::gen_one_case_report(result);
			for (auto line : vec)
			{
				auto ok_idx = line.find("Test Result    : OK");
				auto ng_idx = line.find("Test Result    : NG");
				auto fail_idx = line.find("Failure #");
				if ((std::string::npos != ng_idx) ||
					(std::string::npos != fail_idx))
				{
					sates::common::set_stdout_color(sates::common::CONSOLE_COLOR::CONSOLE_COLOR_RED,
					sates::common::CONSOLE_COLOR::CONSOLE_COLOR_BLACK);
					std::cout << sates::common::get_stdout_color() << line;

					sates::common::clear_stdout_color();
					sates::common::set_stdout_color(sates::common::CONSOLE_COLOR::CONSOLE_COLOR_WHITE,
					sates::common::CONSOLE_COLOR::CONSOLE_COLOR_BLACK);
					//std::cout << "";
				}
				else if (std::string::npos != ok_idx)
				{
					sates::common::set_stdout_color(sates::common::CONSOLE_COLOR::CONSOLE_COLOR_GREEN,
						sates::common::CONSOLE_COLOR::CONSOLE_COLOR_BLACK);
						std::cout << sates::common::get_stdout_color() << line;

						sates::common::clear_stdout_color();
						sates::common::set_stdout_color(sates::common::CONSOLE_COLOR::CONSOLE_COLOR_WHITE,
							sates::common::CONSOLE_COLOR::CONSOLE_COLOR_BLACK);
				}
				else
				{
					std::cout << line;
				}
			}
			tc::tc_result_list::get_instance()->add_result(result);
		}

		void tc_runner::run()
		{
			auto p_vec = tc::test_case_list::get_runnable_test_cases();
			tc::tc_result_list::get_instance()->mark_tc_started();
			for (auto p_case : (*p_vec))
			{
				run_one_test_case(p_case);
			}
			tc::tc_result_list::get_instance()->mark_tc_completed();
		}
	}
}



