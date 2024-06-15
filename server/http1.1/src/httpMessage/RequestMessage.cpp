#include "RequestMessage.hpp"

RequestMessage::RequestMessage()
: mRequestLine()
, mRequestHeaderFields()
, mMessageBody()
{
}
RequestMessage::~RequestMessage()
{
}
void RequestMessage::parse(std::string& request)
{
    std::istringstream requestStream(request);
    try
    {
        parseRequestLine(requestStream);
        parseRequestHeaderFields(requestStream);
        parseMessageBody(requestStream);
    }
    catch(const std::exception& e)
    {
        // TODO: handle exception
    }
}
void RequestMessage::parseRequestLine(std::istringstream& requestStream)
{
    std::string requestLine;
    std::getline(requestStream, requestLine);
    try
    {
        mRequestLine.parseRequestLine(requestLine);
    }
    catch(const std::exception& e)
    {
        throw e;
    }
}
