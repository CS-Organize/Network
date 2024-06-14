#include "MessageBody.hpp"

MessageBody::MessageBody()
: mContent("")
{
}
MessageBody::~MessageBody()
{
}
void MessageBody::parseMessageBody(const std::string& body)
{
    mContent = body;
}
