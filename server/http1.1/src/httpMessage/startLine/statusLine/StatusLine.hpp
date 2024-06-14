#ifndef STATUS_LINE_HPP
#define STATUS_LINE_HPP

#include <string>

class StatusLine
{
private:
    std::string mHTTPVersion;
    std::string mStatusCode;
    std::string mReasonPhrase;
    StatusLine(const StatusLine& rhs);
    StatusLine& operator=(const StatusLine& rhs);

public:
    StatusLine();
    ~StatusLine();
    void setHTTPVersion(const std::string& httpVersion);
    void setStatusCode(const std::string& statusCode);
    void setReasonPhrase(const std::string& reasonPhrase);
};
#endif
