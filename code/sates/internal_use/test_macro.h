//------------------------------------------------------------------------------
// Copyright (C) 2018, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates_test_cpp_deploy.h
//------------------------------------------------------------------------------

#ifndef __SATES_TEST_MACRO_H__
#define __SATES_TEST_MACRO_H__

#include <sates/internal_use/testcode.h>
#include <sates/internal_use/testcode_list.h>

#ifdef SATES_TEST_INIT
#undef SATES_TEST_INIT
#endif

#ifdef SATES_TEST_RUN
#undef SATES_TEST_RUN
#endif

#ifdef SATES_TEST_TERMINATE
#undef SATES_TEST_TERMINATE
#endif


#define SATES_TEST_INIT(TEST_CASE_NAME) \
        class TEST_CASE_NAME : public sates::internal_use::testcode \
        { \
            public: \
                TEST_CASE_NAME(); \
                virtual ~TEST_CASE_NAME(); \
                virtual void init(); \
				virtual void run(); \
				virtual void terminate(); \
        }; \
        \
        TEST_CASE_NAME* g_p_test_instance_##TEST_CASE_NAME \
        = new TEST_CASE_NAME; \
        TEST_CASE_NAME::TEST_CASE_NAME() \
        { \
            m_test_case_name = #TEST_CASE_NAME; \
			sates::internal_use::testcode_list::add_testcode(this); \
        } \
        \
        TEST_CASE_NAME::~TEST_CASE_NAME() {} \
        void TEST_CASE_NAME::init()

#define SATES_TEST_RUN(TEST_CASE_NAME) \
		void TEST_CASE_NAME::run()

#define SATES_TEST_TERMINATE(TEST_CASE_NAME) \
		void TEST_CASE_NAME::terminate()

#endif // __SATES_TEST_MACRO_H__

