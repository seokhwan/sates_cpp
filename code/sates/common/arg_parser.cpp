#include "arg_parser.h"

#include "arg_sates_output.h"

#include <sates/common/err_proc.h>
#include <map>
#include <cstdlib>
#include <algorithm>

namespace sates
{
namespace common
{

static std::map<std::string, std::vector<std::string>> data_map;

static std::map<std::string, void(*)(std::map<std::string, std::vector<std::string>>&, const std::string&)> func_map;


static void fill_data_map(std::string& str_option, std::string& str_data)
{
    auto iter = func_map.find(str_option);
    if (func_map.end() != iter)
    {
        iter->second(data_map, str_data);
    }
    else
    {
        auto func = [](std::string& str_option)
        {
            std::cout << "The option : " << str_option << "is not supported" << std::endl;
            exit(EXIT_FAILURE);
        };
        sates::common::err_proc("", func, str_option);
    }
}

static std::string remove_double_quote(std::string& str)
{
    auto p_str = str.c_str();

    if (str.size() > 0U)
    {
        if ('\"' == p_str[0])
        {
            str.erase(0, 1U);
        }
    }

    if (str.size() > 1U)
    {
        if ('\"' == p_str[str.size() - 1U])
        {
            str.erase(str.size() - 1U, 1U);
        }
    }

    return str;
}

static void init_func_map()
{
    func_map.emplace(arg_sates_output::str_option, arg_sates_output::fill_data);
}

static std::string get_upper_case(const std::string& str)
{
    auto p_char = str.c_str();
    std::string upper_var;
    for (size_t i = 0U; i < str.size(); i++)
    {
        upper_var += std::toupper(p_char[i]);
    }
    return upper_var;
}

static void set_vals_with_env_vars()
{
    for (auto item : func_map)
    {
        auto upper_var = get_upper_case(item.first);
        auto env_var = std::getenv(upper_var.c_str());
        if (nullptr != env_var)
        {
            std::string raw_data = env_var;
            auto str_data = remove_double_quote(raw_data);
            item.second(data_map, str_data);
        }
    }
}

void arg_parser::parse(int argc, const char** argv)
{
    // 1. 함수 맵 초기화
    init_func_map();

    // 2. 환경변수의 값을 활용하여 변수 값 셋팅
    set_vals_with_env_vars();

    // 3. 각 arg 파싱, arg 를 나중에 하기 때문에
    // 위의 (2) 와 arg 값이 모두 존재하는 경우
    // arg 값을 사용.
    for (int i = 0; i < argc; i++)
    {
        std::string str = argv[i];
        auto idx = str.find_first_of("=");
        if (idx != std::string::npos)
        {
            auto str_option = str.substr(0, idx);
            str_option = remove_double_quote(str_option);
            auto str_val = str.substr(idx + 1U, str.size());
            str_val = remove_double_quote(str_val);

            // 5. option 에서 -- 제거
            if (str_option.find_first_of("--") == 0U)
            {
                str_option = str_option.substr(2U, str_option.size());
            }
            fill_data_map(str_option, str_val);
        }
    }
}

void arg_parser::get_arg(const std::string& str_option, std::vector<std::string>& vec)
{
    vec.clear();
    auto iter = data_map.find(str_option);
    if (data_map.end() != iter)
    {
        vec = iter->second;
    }
}

}
}


