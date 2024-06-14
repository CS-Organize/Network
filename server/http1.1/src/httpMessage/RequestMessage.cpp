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
    try
    {
        mRequestLine.parseRequestLine(request);
        mRequestHeaderFields.parseRequestHeaderFields(request);
        mMessageBody.parseMessageBody(request);
    }
    catch(const std::exception& e)
    {
        // TODO: handle exception
    }
}
