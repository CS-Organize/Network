#ifndef RESPONSE_HEADER_FIELDS_HPP
#define RESPONSE_HEADER_FIELDS_HPP

#include <string>

class ResponseHeaderFields
{
private:
    // https://en.wikipedia.org/wiki/List_of_HTTP_header_fields#Standard_response_fields
    std::string mAccessControlAllowOrigin;
    std::string mAcceptPatch;
    std::string mAcceptRanges;
    std::string mAccessControlAllowCredentials;
    std::string mAccessControlAllowHeaders;
    std::string mAccessControlAllowMethods;
    std::string mAccessControlExposeHeaders;
    std::string mAccessControlMaxAge;
    std::string mAge;
    std::string mAllow;
    std::string mAltSvc;
    std::string mCacheControl;
    std::string mConnection;
    std::string mContentDisposition;
    std::string mContentEncoding;
    std::string mContentLanguage;
    std::string mContentLength;
    std::string mContentLocation;
    std::string mContentRange;
    std::string mContentType;
    std::string mDate;
    std::string mDeltaBase;
    std::string mETag;
    std::string mExpires;
    std::string mIM;
    std::string mLastModified;
    std::string mLink;
    std::string mLocation;
    std::string mP3P;
    std::string mPragma;
    std::string mPreferenceApplied;
    std::string mProxyAuthenticate;
    std::string mPublicKeyPins;
    std::string mRetryAfter;
    std::string mServer;
    std::string mSetCookie;
    std::string mStrictTransportSecurity;
    std::string mTk;
    std::string mTrailer;
    std::string mTransferEncoding;
    std::string mUpgrade;
    std::string mVary;
    std::string mVia;
    std::string mWWWAuthenticate;

    ResponseHeaderFields(const ResponseHeaderFields& rhs);
    const ResponseHeaderFields& operator=(const ResponseHeaderFields& rhs);

public:
    ResponseHeaderFields();
    ~ResponseHeaderFields();
    virtual void verifyHeaders(void) const;
    const std::string& getAccessControlAllowOrigin() const;
    const std::string& getAccessControlAllowCredentials() const;
    const std::string& getAccessControlExposeHeaders() const;
    const std::string& getAccessControlMaxAge() const;
    const std::string& getAccessControlAllowMethods() const;
    const std::string& getAccessControlAllowHeaders() const;
    const std::string& getAcceptPatch() const;
    const std::string& getAcceptRanges() const;
    const std::string& getAge() const;
    const std::string& getAllow() const;
    const std::string& getAltSvc() const;
    const std::string& getCacheControl() const;
    const std::string& getConnection() const;
    const std::string& getContentDisposition() const;
    const std::string& getContentEncoding() const;
    const std::string& getContentLanguage() const;
    const std::string& getContentLength() const;
    const std::string& getContentLocation() const;
    const std::string& getContentRange() const;
    const std::string& getContentType() const;
    const std::string& getDate() const;
    const std::string& getDeltaBase() const;
    const std::string& getETag() const;
    const std::string& getExpires() const;
    const std::string& getIM() const;
    const std::string& getLastModified() const;
    const std::string& getLink() const;
    const std::string& getLocation() const;
    const std::string& getP3P() const;
    const std::string& getPragma() const;
    const std::string& getPreferenceApplied() const;
    const std::string& getProxyAuthenticate() const;
    const std::string& getPublicKeyPins() const;
    const std::string& getRetryAfter() const;
    const std::string& getServer() const;
    const std::string& getSetCookie() const;
    const std::string& getStrictTransportSecurity() const;
    const std::string& getTk() const;
    const std::string& getTrailer() const;
    const std::string& getTransferEncoding() const;
    const std::string& getUpgrade() const;
    const std::string& getVary() const;
    const std::string& getVia() const;
    const std::string& getWWWAuthenticate() const;
    void setAccessControlAllowOrigin(
        const std::string& accessControlAllowOrigin);
    void setAccessControlAllowCredentials(
        const std::string& accessControlAllowCredentials);
    void setAccessControlExposeHeaders(
        const std::string& accessControlExposeHeaders);
    void setAccessControlMaxAge(const std::string& accessControlMaxAge);
    void setAccessControlAllowMethods(
        const std::string& accessControlAllowMethods);
    void setAccessControlAllowHeaders(
        const std::string& accessControlAllowHeaders);
    void setAcceptPatch(const std::string& acceptPatch);
    void setAcceptRanges(const std::string& acceptRanges);
    void setAge(const std::string& age);
    void setAllow(const std::string& allow);
    void setAltSvc(const std::string& altSvc);
    void setCacheControl(const std::string& cacheControl);
    void setConnection(const std::string& connection);
    void setContentDisposition(const std::string& contentDisposition);
    void setContentEncoding(const std::string& contentEncoding);
    void setContentLanguage(const std::string& contentLanguage);
    void setContentLength(const std::string& contentLength);
    void setContentLocation(const std::string& contentLocation);
    void setContentRange(const std::string& contentRange);
    void setContentType(const std::string& contentType);
    void setDate(const std::string& date);
    void setDeltaBase(const std::string& deltaBase);
    void setETag(const std::string& eTag);
    void setExpires(const std::string& expires);
    void setIM(const std::string& iM);
    void setLastModified(const std::string& lastModified);
    void setLink(const std::string& link);
    void setLocation(const std::string& location);
    void setP3P(const std::string& p3p);
    void setPragma(const std::string& pragma);
    void setPreferenceApplied(const std::string& preferenceApplied);
    void setProxyAuthenticate(const std::string& proxyAuthenticate);
    void setPublicKeyPins(const std::string& publicKeyPins);
    void setRetryAfter(const std::string& retryAfter);
    void setServer(const std::string& server);
    void setSetCookie(const std::string& setCookie);
    void setStrictTransportSecurity(const std::string& strictTransportSecurity);
    void setTk(const std::string& tk);
    void setTrailer(const std::string& trailer);
    void setTransferEncoding(const std::string& transferEncoding);
    void setUpgrade(const std::string& upgrade);
    void setVary(const std::string& vary);
    void setVia(const std::string& via);
    void setWWWAuthenticate(const std::string& wwwAuthenticate);
};

#endif
