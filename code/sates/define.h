//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
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

#ifndef SATES_WIN
	#define SATES_EXPORT
#endif

#include <cstddef>
#include <stdint.h>

#ifndef SATES_SAFE_DELETE
#define SATES_SAFE_DELETE(ptr) if (nullptr != ptr) {delete ptr;}
#endif 

#endif // __SATES_DEFINE_H__
