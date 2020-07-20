#include "writer_factory.h"
#include "plain_text_writer.h"
#include "xml_writer.h"

namespace sates
{
namespace report
{
std::shared_ptr<sates::report::writer> writer_factory::create(const char* p_format)
{
    std::string str_format = p_format;
    if ("plain" == str_format)
    {
        return std::shared_ptr<sates::report::writer>(new plain_text_writer);
    }
    else if ("xml" == str_format)
    {
        return std::shared_ptr<sates::report::writer>(new xml_writer);
    }
    else
    {
        return std::shared_ptr<sates::report::writer>(nullptr);
    }
}

}
}

