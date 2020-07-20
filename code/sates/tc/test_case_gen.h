//------------------------------------------------------------------------------
// Copyright (C) 2018 - Present, Seokhwan Kim (kim at seokhwan.net)
// This file is part of "the SATES"
// For conditions of distribution and use, see copyright notice in 
// sates/sates.h
//------------------------------------------------------------------------------

#ifndef __SATES_TEST_CASE_GEN_H__
#define __SATES_TEST_CASE_GEN_H__

#include <sates/tc/test_case.h>
#include <sates/tc/test_case_list.h>

#ifdef SATES_TEST_INIT
#undef SATES_TEST_INIT
#endif

#ifdef SATES_TEST_RUN
#undef SATES_TEST_RUN
#endif

#ifdef SATES_TEST_TERMINATE
#undef SATES_TEST_TERMINATE
#endif


#define SATES_TEST_RUN(TEST_CASE_NAME) \
        class __SaTeS_ClS_MaNgLe_##TEST_CASE_NAME : public sates::tc::test_case \
        { \
            public: \
                __SaTeS_ClS_MaNgLe_##TEST_CASE_NAME(); \
                virtual ~__SaTeS_ClS_MaNgLe_##TEST_CASE_NAME(); \
				virtual void run(); \
        }; \
        \
        __SaTeS_ClS_MaNgLe_##TEST_CASE_NAME* g_p_test_instance_##TEST_CASE_NAME \
        = new __SaTeS_ClS_MaNgLe_##TEST_CASE_NAME; \
        __SaTeS_ClS_MaNgLe_##TEST_CASE_NAME::__SaTeS_ClS_MaNgLe_##TEST_CASE_NAME() \
        { \
            m_test_case_name = #TEST_CASE_NAME; \
			sates::tc::test_case_list::add_test_case(this); \
        } \
        \
        __SaTeS_ClS_MaNgLe_##TEST_CASE_NAME::~__SaTeS_ClS_MaNgLe_##TEST_CASE_NAME() {} \
        void __SaTeS_ClS_MaNgLe_##TEST_CASE_NAME::run()


#endif // __SATES_TEST_CASE_GEN_H__

