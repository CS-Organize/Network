#ifndef REQUEST_MESSAGE_HPP
#define REQUEST_MESSAGE_HPP

#include "MessageBody.hpp"
#include "RequestHeaderFields.hpp"
#include "RequestLine.hpp"

class RequestMessage
{
private:
    RequestLine mRequestLine;
    RequestHeaderFields mRequestHeaderFields;
    MessageBody mMessageBody;
    RequestMessage(const RequestMessage& rhs);
    RequestMessage& operator=(const RequestMessage& rhs);

public:
    RequestMessage();
    ~RequestMessage();
    void parse(std::string& request);
};

#endif
