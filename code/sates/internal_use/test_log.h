#ifndef __SATES_INTERNAL_USE_TEST_LOG_H__
#define __SATES_INTERNAL_USE_TEST_LOG_H__

#include <sates/define.h>
#include <vector>
#include <string>

namespace sates
{
	namespace internal_use
	{
		class test_log
		{
		public:
			static void start_new_test();
			static void error(const std::string& error_message);
			static bool is_err_occurred();
			static std::vector<std::string>* get_accumulated_logs();
		};
	}
}

#endif // __SATES_INTERNAL_USE_TEST_LOG_H__

