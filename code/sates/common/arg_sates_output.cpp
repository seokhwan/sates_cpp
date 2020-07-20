#include "arg_sates_output.h"

namespace sates
{
namespace common
{
const std::string arg_sates_output::str_option("sates_output");

void arg_sates_output::fill_data(std::map<std::string, std::vector<std::string>>& data_map, const std::string& str_data)
{
    auto idx = str_data.find_first_of(":");
    if (std::string::npos != idx)
    {
        auto str_format = str_data.substr(0U, idx);
        auto str_file_path = str_data.substr(idx + 1U, str_data.size());

        if (str_format.size() > 0U &&
            str_file_path.size() > 0U)
        {
            std::vector<std::string> val_vec;
            val_vec.push_back(str_format);
            val_vec.push_back(str_file_path);

            auto iter = data_map.find(str_option);
            if (data_map.end() != iter)
            {
                data_map.erase(iter);
            }
            data_map.emplace(str_option, val_vec);
        }
    }
}
	
}
}


