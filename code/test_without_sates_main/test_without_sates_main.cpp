#include <sates/sates.h>

SATES_TEST_INIT(T1) {}

SATES_TEST_RUN(T1)
{
    SATES_EQ(0, 1);
}

SATES_TEST_TERMINATE(T1) {}

SATES_TEST_INIT(T2) {}

SATES_TEST_RUN(T2)
{
    SATES_EQ(0, 1);
}

SATES_TEST_TERMINATE(T2) {}


int main(int argc, char** argv)
{
    sates::run();
    sates::print_result(nullptr);
    return 0;
}