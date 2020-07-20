#include "tc_result_list.h"

namespace sates
{
    namespace tc
    {
        static std::vector<tc_result> result_vec;
        static tc_result_list* g_p_instance = nullptr;
        tc_result_list* tc_result_list::get_instance()
        {
            if (nullptr == g_p_instance)
            {
                g_p_instance = new tc_result_list();
            }
            return g_p_instance;
        }

        tc_result_list::tc_result_list() : tc_result("AllTests")
        {
            
        }

        tc_result_list::~tc_result_list() {} 
        
        void tc_result_list::add_result(const tc_result& result)
        {
            if ("OK" != result.test_ok_ng)
            {
                this->test_ok_ng = "NG";
            }
            result_vec.push_back(result);
        }

        uint32_t tc_result_list::get_total_num_of_failures()
        {
            uint32_t retval = 0U;
            for (auto item : result_vec)
            {
                retval += item.failures;
            }

            return retval;
        }

        uint32_t tc_result_list::get_total_num_of_failure_test_cases()
        {
            uint32_t retval = 0U;
            for (auto item : result_vec)
            {
                if (item.failures > 0U)
                {
                    retval++;
                }
            }
            return retval;
        }

        float tc_result_list::get_total_taken_time()
        {
            float retval = 0.F;
            for (auto item : result_vec)
            {
                retval += item.get_taken_time_ms();
            }

            return retval;
        }

        uint32_t tc_result_list::get_num_of_tc()
        {
            return static_cast<uint32_t>(result_vec.size());
        }

        const std::vector<tc_result>* tc_result_list::get_list() const
        {
            return &result_vec;
        }
    }
}