#include "RequestLine.hpp"

RequestLine::RequestLine()
: mMethod("")
, mRequestURL("")
, mHTTPVersion("")
{
}
RequestLine::~RequestLine()
{
}
void RequestLine::parseRequestLine(const std::string& requestLine)
{
    (void)requestLine;
    // TODO: parse request line
}
std::string RequestLine::getMethod(void) const
{
    return mMethod;
}
std::string RequestLine::getRequestURL(void) const
{
    return mRequestURL;
}
std::string RequestLine::getHTTPVersion(void) const
{
    return mHTTPVersion;
}
