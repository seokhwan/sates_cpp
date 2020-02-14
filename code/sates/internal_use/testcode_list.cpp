#include <sates/internal_use/testcode_list.h>
#include <sates/internal_use/test_list_editor.h>
#include <sates/internal_use/test_runner.h>

#include <map>
#include <vector>
#include <memory>

namespace sates
{
namespace internal_use
{
typedef std::map<std::string, testcode*> code_map_t;
static code_map_t* p_testcode_map = nullptr;

void testcode_list::create()
{
	static bool is_created = false;
	if (!is_created)
	{
		is_created = true;
		p_testcode_map = new code_map_t();
	}
}

void testcode_list::destroy()
{
	SATES_SAFE_DELETE(p_testcode_map);
}

void testcode_list::add_testcode(testcode* p_code)
{
	create();
	if (nullptr != p_code)
	{
		code_map_t::iterator iter = p_testcode_map->find(p_code->get_test_case_name());
		if (p_testcode_map->end() == iter)
		{
			(*p_testcode_map)[p_code->get_test_case_name()] = p_code;
		}
		else
		{
			// exception
		}
	}
	else
	{
		// exception
	}
	
}

testcode* testcode_list::get_testcode(const char_t* p_test_case_name)
{
	create();
	testcode* p_retval = nullptr;

	if (nullptr != p_test_case_name)
	{
		code_map_t::iterator iter = p_testcode_map->find(p_test_case_name);
		if (p_testcode_map->end() != iter)
		{
			p_retval = iter->second;
		}
	}
	else
	{
		// exception
	}
	
	return p_retval;
}

void testcode_list::include_testcode(const char_t* p_test_case_name)
{
	sates::internal_use::test_list_editor::include_test(p_test_case_name);
}

void testcode_list::exclude_testcode(const char_t* p_test_case_name)
{
	sates::internal_use::test_list_editor::exclude_test(p_test_case_name);
}

void testcode_list::run()
{
	sates::internal_use::test_runner::run(
		sates::internal_use::test_list_editor::get_include_list(),
		sates::internal_use::test_list_editor::get_exclude_list(),
		p_testcode_map);
}

void testcode_list::print_result(const char* p_outfile)
{
	for (auto item : (*p_testcode_map))
	{
		item.second->print(p_outfile);
	}
}
}
}

