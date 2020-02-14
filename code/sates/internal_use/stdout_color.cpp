//------------------------------------------------------------------------------
//
// Copyright 2018, SATES
// All rights reserved.
//
// Author: kim at seokhwan.net (Seokhwan Kim)
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met :
//
// 1. Redistributions of source code must retain the above copyright notice, 
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, 
// this list of conditions and the following disclaimer in the documentation 
// and / or other materials provided with the distribution.
//
// 3. Neither the name of SATES nor the names of its 
// contributors may be used to endorse or promote products derived from this 
// software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.
//
//------------------------------------------------------------------------------

#include <sates/internal_use/stdout_color.h>
#include <iostream>

namespace sates 
{
namespace internal_use
{

std::string g_color_code_string;

void set_stdout_color(CONSOLE_COLOR text_color, CONSOLE_COLOR background_color)
{
	switch (text_color)
	{
	case CONSOLE_COLOR_RED:
		g_color_code_string = "\033[0;31;";
		break;
	case CONSOLE_COLOR_GREEN:
		g_color_code_string = "\033[0;32;";
		break;
	case CONSOLE_COLOR_BLUE:
		g_color_code_string = "\033[0;34;";
		break;
	case CONSOLE_COLOR_WHITE:
		g_color_code_string = "\033[0;37;";
		break;
	case CONSOLE_COLOR_BLACK:
		g_color_code_string = "\033[0;30;";
		break;
	default:
		g_color_code_string = "\033[0;37;";
		break;
	}

	switch (background_color)
	{
	case CONSOLE_COLOR_RED:
		g_color_code_string += "41m";
		break;
	case CONSOLE_COLOR_GREEN:
		g_color_code_string += "42m";
		break;
	case CONSOLE_COLOR_BLUE:
		g_color_code_string += "44m";
		break;
	case CONSOLE_COLOR_WHITE:
		g_color_code_string += "47m";
		break;
	case CONSOLE_COLOR_BLACK:
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