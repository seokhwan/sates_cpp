//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include <sates/internal_use/common_func.h>

namespace sates
{
	namespace internal_use
	{
		bool is_in_the_list(const char* p_test_case_name, std::vector<std::string>* p_list)
		{
			bool retval = false;
			std::string str_case_name = p_test_case_name;

			// old syntax
			//for (std::vector<std::string>::iterator iter = p_list->begin();
			//	iter != p_list->end();
			//	iter++)
			//{
			//	if ((*iter) == p_test_case_name)
			//	{
			//		retval = true;
			//		break;
			//	}
			//}

			// new syntax
			for (auto item : (*p_list))
			{
				if (item == str_case_name)
				{
					retval = true;
					break;
				}
			}
			return retval;
		}
	}
}