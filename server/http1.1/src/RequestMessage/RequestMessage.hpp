#ifndef REQUEST_MESSAGE_HPP
#define REQUEST_MESSAGE_HPP

#include <string>

class RequestMessage
{
private:
    std::string mMethod;
    std::string mRequest_URI;
    std::string mHTTP_Version;

    /* HTTP/1.1 Standard Request Header Fields */
    // https://en.wikipedia.org/wiki/List_of_HTTP_header_fields#Standard_request_fields
    std::string mA_IM;
    std::string mAccept;
    std::string mAccept_Charset;
    std::string mAccept_Encoding;
    std::string mAccept_Language;
    std::string mAccess_Control_Request_Method;
    std::string mAccess_Control_Request_Headers;
    std::string mAuthorization;
    std::string mCache_Control;
    std::string mConnection;
    std::string mContent_Encoding;
    std::string mContent_Length;
    std::string mContent_Type;
    std::string mCookie;
    std::string mDate;
    std::string mExpect;
    std::string mForwarded;
    std::string mFrom;
    std::string mHost;
    std::string mIf_Match;
    std::string mIf_Modified_Since;
    std::string mIf_None_Match;
    std::string mIf_Range;
    std::string mIf_Unmodified_Since;
    std::string mMax_Forwards;
    std::string mOrigin;
    std::string mPragma;
    std::string mPrefer;
    std::string mProxy_Authorization;
    std::string mRange;
    std::string mReferer;
    std::string mTE;
    std::string mTrailer;
    std::string mTransfer_Encoding;
    std::string mUser_Agent;
    std::string mUpgrade;
    std::string mVia;
    /* ~HTTP/1.1 Standard Request Header Fields */

    std::string mMessage_Body;
    void parseRequestLine(std::string& request);
    // void checkSyntaxOfRequestLine(std::string& request);
    void parseHeaderFields(std::string& request);
    void parseMessageBody(std::string& request);
public:
    RequestMessage();
    ~RequestMessage();
    void Parse(std::string request);
};




#endif
