#include "ResponseHeaderFields.hpp"

ResponseHeaderFields::ResponseHeaderFields()
: mAccessControlAllowOrigin("")
, mAcceptPatch("")
, mAcceptRanges("")
, mAccessControlAllowCredentials("")
, mAccessControlAllowHeaders("")
, mAccessControlAllowMethods("")
, mAccessControlExposeHeaders("")
, mAccessControlMaxAge("")
, mAge("")
, mAllow("")
, mAltSvc("")
, mCacheControl("")
, mConnection("")
, mContentDisposition("")
, mContentEncoding("")
, mContentLanguage("")
, mContentLength("")
, mContentLocation("")
, mContentRange("")
, mContentType("")
, mDate("")
, mDeltaBase("")
, mETag("")
, mExpires("")
, mIM("")
, mLastModified("")
, mLink("")
, mLocation("")
, mP3P("")
, mPragma("")
, mPreferenceApplied("")
, mProxyAuthenticate("")
, mPublicKeyPins("")
, mRetryAfter("")
, mServer("")
, mSetCookie("")
, mStrictTransportSecurity("")
, mTk("")
, mTrailer("")
, mTransferEncoding("")
, mUpgrade("")
, mVary("")
, mVia("")
, mWWWAuthenticate("")

{
}
ResponseHeaderFields::~ResponseHeaderFields()
{
}
void ResponseHeaderFields::verifyHeaders(void) const
{
}
const std::string& ResponseHeaderFields::getAccessControlAllowOrigin() const
{
    return mAccessControlAllowOrigin;
}
const std::string& ResponseHeaderFields::getAccessControlAllowCredentials() const
{
    return mAccessControlAllowCredentials;
}
const std::string& ResponseHeaderFields::getAccessControlExposeHeaders() const
{
    return mAccessControlExposeHeaders;
}
const std::string& ResponseHeaderFields::getAccessControlMaxAge() const
{
    return mAccessControlMaxAge;
}
const std::string& ResponseHeaderFields::getAccessControlAllowMethods() const
{
    return mAccessControlAllowMethods;
}
const std::string& ResponseHeaderFields::getAccessControlAllowHeaders() const
{
    return mAccessControlAllowHeaders;
}
const std::string& ResponseHeaderFields::getAcceptPatch() const
{
    return mAcceptPatch;
}
const std::string& ResponseHeaderFields::getAcceptRanges() const
{
    return mAcceptRanges;
}
const std::string& ResponseHeaderFields::getAge() const
{
    return mAge;
}
const std::string& ResponseHeaderFields::getAllow() const
{
    return mAllow;
}
const std::string& ResponseHeaderFields::getAltSvc() const
{
    return mAltSvc;
}
const std::string& ResponseHeaderFields::getCacheControl() const
{
    return mCacheControl;
}
const std::string& ResponseHeaderFields::getConnection() const
{
    return mConnection;
}
const std::string& ResponseHeaderFields::getContentDisposition() const
{
    return mContentDisposition;
}
const std::string& ResponseHeaderFields::getContentEncoding() const
{
    return mContentEncoding;
}
const std::string& ResponseHeaderFields::getContentLanguage() const
{
    return mContentLanguage;
}
const std::string& ResponseHeaderFields::getContentLength() const
{
    return mContentLength;
}
const std::string& ResponseHeaderFields::getContentLocation() const
{
    return mContentLocation;
}
const std::string& ResponseHeaderFields::getContentRange() const
{
    return mContentRange;
}
const std::string& ResponseHeaderFields::getContentType() const
{
    return mContentType;
}
const std::string& ResponseHeaderFields::getDate() const
{
    return mDate;
}
const std::string& ResponseHeaderFields::getDeltaBase() const
{
    return mDeltaBase;
}
const std::string& ResponseHeaderFields::getETag() const
{
    return mETag;
}
const std::string& ResponseHeaderFields::getExpires() const
{
    return mExpires;
}
const std::string& ResponseHeaderFields::getIM() const
{
    return mIM;
}
const std::string& ResponseHeaderFields::getLastModified() const
{
    return mLastModified;
}
const std::string& ResponseHeaderFields::getLink() const
{
    return mLink;
}
const std::string& ResponseHeaderFields::getLocation() const
{
    return mLocation;
}
const std::string& ResponseHeaderFields::getP3P() const
{
    return mP3P;
}
const std::string& ResponseHeaderFields::getPragma() const
{
    return mPragma;
}
const std::string& ResponseHeaderFields::getPreferenceApplied() const
{
    return mPreferenceApplied;
}
const std::string& ResponseHeaderFields::getProxyAuthenticate() const
{
    return mProxyAuthenticate;
}
const std::string& ResponseHeaderFields::getPublicKeyPins() const
{
    return mPublicKeyPins;
}
const std::string& ResponseHeaderFields::getRetryAfter() const
{
    return mRetryAfter;
}
const std::string& ResponseHeaderFields::getServer() const
{
    return mServer;
}
const std::string& ResponseHeaderFields::getSetCookie() const
{
    return mSetCookie;
}
const std::string& ResponseHeaderFields::getStrictTransportSecurity() const
{
    return mStrictTransportSecurity;
}
const std::string& ResponseHeaderFields::getTk() const
{
    return mTk;
}
const std::string& ResponseHeaderFields::getTrailer() const
{
    return mTrailer;
}
const std::string& ResponseHeaderFields::getTransferEncoding() const
{
    return mTransferEncoding;
}
const std::string& ResponseHeaderFields::getUpgrade() const
{
    return mUpgrade;
}
const std::string& ResponseHeaderFields::getVary() const
{
    return mVary;
}
const std::string& ResponseHeaderFields::getVia() const
{
    return mVia;
}
const std::string& ResponseHeaderFields::getWWWAuthenticate() const
{
    return mWWWAuthenticate;
}
void ResponseHeaderFields::setAccessControlAllowOrigin(
    const std::string& accessControlAllowOrigin)
{
    mAccessControlAllowOrigin = accessControlAllowOrigin;
}
void ResponseHeaderFields::setAccessControlAllowCredentials(
    const std::string& accessControlAllowCredentials)
{
    mAccessControlAllowCredentials = accessControlAllowCredentials;
}
void ResponseHeaderFields::setAccessControlExposeHeaders(
    const std::string& accessControlExposeHeaders)
{
    mAccessControlExposeHeaders = accessControlExposeHeaders;
}
void ResponseHeaderFields::setAccessControlMaxAge(
    const std::string& accessControlMaxAge)
{
    mAccessControlMaxAge = accessControlMaxAge;
}
void ResponseHeaderFields::setAccessControlAllowMethods(
    const std::string& accessControlAllowMethods)
{
    mAccessControlAllowMethods = accessControlAllowMethods;
}
void ResponseHeaderFields::setAccessControlAllowHeaders(
    const std::string& accessControlAllowHeaders)
{
    mAccessControlAllowHeaders = accessControlAllowHeaders;
}
void ResponseHeaderFields::setAcceptPatch(const std::string& acceptPatch)
{
    mAcceptPatch = acceptPatch;
}
void ResponseHeaderFields::setAcceptRanges(const std::string& acceptRanges)
{
    mAcceptRanges = acceptRanges;
}
void ResponseHeaderFields::setAge(const std::string& age)
{
    mAge = age;
}
void ResponseHeaderFields::setAllow(const std::string& allow)
{
    mAllow = allow;
}
void ResponseHeaderFields::setAltSvc(const std::string& altSvc)
{
    mAltSvc = altSvc;
}
void ResponseHeaderFields::setCacheControl(const std::string& cacheControl)
{
    mCacheControl = cacheControl;
}
void ResponseHeaderFields::setConnection(const std::string& connection)
{
    mConnection = connection;
}
void ResponseHeaderFields::setContentDisposition(
    const std::string& contentDisposition)
{
    mContentDisposition = contentDisposition;
}
void ResponseHeaderFields::setContentEncoding(const std::string& contentEncoding)
{
    mContentEncoding = contentEncoding;
}
void ResponseHeaderFields::setContentLanguage(const std::string& contentLanguage)
{
    mContentLanguage = contentLanguage;
}
void ResponseHeaderFields::setContentLength(const std::string& contentLength)
{
    mContentLength = contentLength;
}
void ResponseHeaderFields::setContentLocation(const std::string& contentLocation)
{
    mContentLocation = contentLocation;
}
void ResponseHeaderFields::setContentRange(const std::string& contentRange)
{
    mContentRange = contentRange;
}
void ResponseHeaderFields::setContentType(const std::string& contentType)
{
    mContentType = contentType;
}
void ResponseHeaderFields::setDate(const std::string& date)
{
    mDate = date;
}
void ResponseHeaderFields::setDeltaBase(const std::string& deltaBase)
{
    mDeltaBase = deltaBase;
}
void ResponseHeaderFields::setETag(const std::string& eTag)
{
    mETag = eTag;
}
void ResponseHeaderFields::setExpires(const std::string& expires)
{
    mExpires = expires;
}
void ResponseHeaderFields::setIM(const std::string& iM)
{
    mIM = iM;
}
void ResponseHeaderFields::setLastModified(const std::string& lastModified)
{
    mLastModified = lastModified;
}
void ResponseHeaderFields::setLink(const std::string& link)
{
    mLink = link;
}
void ResponseHeaderFields::setLocation(const std::string& location)
{
    mLocation = location;
}
void ResponseHeaderFields::setP3P(const std::string& p3p)
{
    mP3P = p3p;
}
void ResponseHeaderFields::setPragma(const std::string& pragma)
{
    mPragma = pragma;
}
void ResponseHeaderFields::setPreferenceApplied(const std::string& preferenceApplied)
{
    mPreferenceApplied = preferenceApplied;
}
void ResponseHeaderFields::setProxyAuthenticate(const std::string& proxyAuthenticate)
{
    mProxyAuthenticate = proxyAuthenticate;
}
void ResponseHeaderFields::setPublicKeyPins(const std::string& publicKeyPins)
{
    mPublicKeyPins = publicKeyPins;
}
void ResponseHeaderFields::setRetryAfter(const std::string& retryAfter)
{
    mRetryAfter = retryAfter;
}
void ResponseHeaderFields::setServer(const std::string& server)
{
    mServer = server;
}
void ResponseHeaderFields::setSetCookie(const std::string& setCookie)
{
    mSetCookie = setCookie;
}
void ResponseHeaderFields::setStrictTransportSecurity(
    const std::string& strictTransportSecurity)
{
    mStrictTransportSecurity = strictTransportSecurity;
}
void ResponseHeaderFields::setTk(const std::string& tk)
{
    mTk = tk;
}
void ResponseHeaderFields::setTrailer(const std::string& trailer)
{
    mTrailer = trailer;
}
void ResponseHeaderFields::setTransferEncoding(const std::string& transferEncoding)
{
    mTransferEncoding = transferEncoding;
}
void ResponseHeaderFields::setUpgrade(const std::string& upgrade)
{
    mUpgrade = upgrade;
}
void ResponseHeaderFields::setVary(const std::string& vary)
{
    mVary = vary;
}
void ResponseHeaderFields::setVia(const std::string& via)
{
    mVia = via;
}
void ResponseHeaderFields::setWWWAuthenticate(const std::string& wwwAuthenticate)
{
    mWWWAuthenticate = wwwAuthenticate;
}
