//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_REPORT_FACTORY_H__
#define __SATES_REPORT_FACTORY_H__

#include <sates/report/writer.h>
#include <memory>

namespace sates
{
namespace report
{
class SATES_EXPORT writer_factory
{
public:
	static std::shared_ptr<sates::report::writer> create(const char* p_format);
};
}
}

#endif // __SATES_WRITER_FACTORY_H__
