//------------------------------------------------------------------------------
// Copyright (C) 2018, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates_test_cpp_deploy.h
//------------------------------------------------------------------------------

#ifndef __SATES_DEFINE_H__
#define __SATES_DEFINE_H__

#ifdef SATES_WIN
	#ifdef _WINDLL
		#define SATES_EXPORT __declspec(dllexport)
	#else
		#define SATES_EXPORT 
	#endif

	#pragma warning( disable : 4251 4996 )
#endif

#ifdef SATES_LINUX
	#define SATES_EXPORT
#endif

#include <cstddef>
#include <stdint.h>

#ifndef CHAR_T_DEFINED
typedef char               char_t;
#define CHAR_T_DEFINED
#endif

#ifndef UCHAR_T_DEFINED
typedef unsigned char      uchar_t;
#define UCHAR_T_DEFINED
#endif

#ifndef FLOAT32_T_DEFINED
typedef float              float32_t;
#define FLOAT32_T_DEFINED
#endif

#ifndef FLOAT64_T_DEFINED
typedef double             float64_t;
#define FLOAT64_T_DEFINED
#endif

#ifndef SATES_SAFE_DELETE
#define SATES_SAFE_DELETE(ptr) if (nullptr != ptr) {delete ptr;}
#endif 

#endif // __SATES_DEFINE_H__
