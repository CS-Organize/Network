#ifndef MESSAGE_BODY_HPP
#define MESSAGE_BODY_HPP

#include <string>

class MessageBody
{
private:
    std::string mContent;
    MessageBody(const MessageBody& rhs);
    MessageBody& operator=(const MessageBody& rhs);
public:
    MessageBody(/* args */);
    ~MessageBody();
    void parseMessageBody(const std::string& body);
};

#endif
