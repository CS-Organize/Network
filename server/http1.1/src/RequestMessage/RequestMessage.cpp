#include "RequestMessage.hpp"
#include "Exception.hpp"
#include <sstream>
#include <iostream>

RequestMessage::RequestMessage(/* args */)
{
}
RequestMessage::~RequestMessage()
{
}
void RequestMessage::Parse(std::string request)
{
    std::istringstream iss(request);
    std::string line;

    try
    {
        parseRequestLine(request);
        parseHeaderFields(request);
        parseMessageBody(request);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
void RequestMessage::parseRequestLine(std::string& request)
{
    std::istringstream iss(request);
    std::string line;

    // Parse Request Line
    std::getline(iss, line);
    std::istringstream line_stream(line);
    line_stream >> mMethod >> mRequest_URI >> mHTTP_Version;
    if (!iss.eof())
    {
        throw InvalidRequestException();
    }
}
void RequestMessage::parseHeaderFields(std::string& request)
{
    (void)request;
}
void RequestMessage::parseMessageBody(std::string& request)
{
    (void)request;
}
