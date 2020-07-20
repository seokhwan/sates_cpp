//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#include "stdout_color.h"
#include <iostream>

namespace sates 
{
namespace common
{

std::string g_color_code_string;

void set_stdout_color(CONSOLE_COLOR text_color, CONSOLE_COLOR background_color)
{
	switch (text_color)
	{
	case CONSOLE_COLOR::CONSOLE_COLOR_RED:
		g_color_code_string = "\033[0;31;";
		break;
	case CONSOLE_COLOR::CONSOLE_COLOR_GREEN:
		g_color_code_string = "\033[0;32;";
		break;
	case CONSOLE_COLOR::CONSOLE_COLOR_BLUE:
		g_color_code_string = "\033[0;34;";
		break;
	case CONSOLE_COLOR::CONSOLE_COLOR_WHITE:
		g_color_code_string = "\033[0;37;";
		break;
	case CONSOLE_COLOR::CONSOLE_COLOR_BLACK:
		g_color_code_string = "\033[0;30;";
		break;
	default:
		g_color_code_string = "\033[0;37;";
		break;
	}

	switch (background_color)
	{
	case CONSOLE_COLOR::CONSOLE_COLOR_RED:
		g_color_code_string += "41m";
		break;
	case CONSOLE_COLOR::CONSOLE_COLOR_GREEN:
		g_color_code_string += "42m";
		break;
	case CONSOLE_COLOR::CONSOLE_COLOR_BLUE:
		g_color_code_string += "44m";
		break;
	case CONSOLE_COLOR::CONSOLE_COLOR_WHITE:
		g_color_code_string += "47m";
		break;
	case CONSOLE_COLOR::CONSOLE_COLOR_BLACK:
		g_color_code_string += "40m";
		break;
	default:
		g_color_code_string += "40m";
		break;
	}
}

std::string get_stdout_color()
{
	return g_color_code_string;
}

void clear_stdout_color()
{
	std::cout << "\033[0m";
}
}
} // using namespace sates