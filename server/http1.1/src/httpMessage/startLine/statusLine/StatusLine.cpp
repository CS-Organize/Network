#include "StatusLine.hpp"

StatusLine::StatusLine()
: mHTTPVersion("")
, mStatusCode("")
, mReasonPhrase("")
{
}
StatusLine::~StatusLine()
{
}
void StatusLine::setHTTPVersion(const std::string& httpVersion)
{
    mHTTPVersion = httpVersion;
}
void StatusLine::setStatusCode(const std::string& statusCode)
{
    mStatusCode = statusCode;
}
void StatusLine::setReasonPhrase(const std::string& reasonPhrase)
{
    mReasonPhrase = reasonPhrase;
}
