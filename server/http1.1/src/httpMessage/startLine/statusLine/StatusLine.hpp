#ifndef STATUS_LINE_HPP
#define STATUS_LINE_HPP

#include <string>

class StatusLine
{
private:
    std::string mHTTPVersion;
    std::string mStatusCode; // istringsteam으로 파싱할 때 "1asd1", 오버플로우 등의 예외처리를 위해 string으로 선언
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
