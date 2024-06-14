#ifndef REQUEST_HEADER_FIELDS_HPP
#define REQUEST_HEADER_FIELDS_HPP

#include <string>

class RequestHeaderFields
{
private:
    // https://en.wikipedia.org/wiki/List_of_HTTP_header_fields#Standard_request_fields
    std::string mA_IM;
    std::string mAccept;
    std::string mAcceptCharset;
    std::string mAcceptEncoding;
    std::string mAcceptLanguage;
    std::string mAccessControlRequestHeaders;
    std::string mAccessControlRequestMethod;
    std::string mAuthorization;
    std::string mCacheControl;
    std::string mConnection;
    std::string mContentEncoding;
    std::string mContentLength;
    std::string mContentType;
    std::string mCookie;
    std::string mDate;
    std::string mExpect;
    std::string mForwarded;
    std::string mFrom;
    std::string mHost;
    std::string mIfMatch;
    std::string mIfModifiedSince;
    std::string mIfNoneMatch;
    std::string mIfRange;
    std::string mIfUnmodifiedSince;
    std::string mMaxForwards;
    std::string mOrigin;
    std::string mPragma;
    std::string mPrefer;
    std::string mProxyAuthorization;
    std::string mRange;
    std::string mReferer;
    std::string mTE;
    std::string mTrailer;
    std::string mTransferEncoding;
    std::string mUpgrade;
    std::string mUserAgent;
    std::string mVia;
    RequestHeaderFields(const RequestHeaderFields& rhs);
    const RequestHeaderFields& operator=(const RequestHeaderFields& rhs);

public:
    RequestHeaderFields();
    ~RequestHeaderFields();
    void parseRequestHeaderFields(const std::string& fields);
    const std::string& getA_IM() const;
    const std::string& getAccept() const;
    const std::string& getAcceptCharset() const;
    const std::string& getAcceptEncoding() const;
    const std::string& getAcceptLanguage() const;
    const std::string& getAccessControlRequestMethod() const;
    const std::string& getAccessControlRequestHeaders() const;
    const std::string& getAuthorization() const;
    const std::string& getCacheControl() const;
    const std::string& getConnection() const;
    const std::string& getContentEncoding() const;
    const std::string& getContentLength() const;
    const std::string& getContentType() const;
    const std::string& getCookie() const;
    const std::string& getDate() const;
    const std::string& getExpect() const;
    const std::string& getForwarded() const;
    const std::string& getFrom() const;
    const std::string& getHost() const;
    const std::string& getIfMatch() const;
    const std::string& getIfModifiedSince() const;
    const std::string& getIfNoneMatch() const;
    const std::string& getIfRange() const;
    const std::string& getIfUnmodifiedSince() const;
    const std::string& getMaxForwards() const;
    const std::string& getOrigin() const;
    const std::string& getPragma() const;
    const std::string& getPrefer() const;
    const std::string& getProxyAuthorization() const;
    const std::string& getRange() const;
    const std::string& getReferer() const;
    const std::string& getTE() const;
    const std::string& getTrailer() const;
    const std::string& getTransferEncoding() const;
    const std::string& getUpgrade() const;
    const std::string& getUserAgent() const;
    const std::string& getVia() const;
};

#endif
