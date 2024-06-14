#include "RequestHeaderFields.hpp"
#include <sstream>

RequestHeaderFields::RequestHeaderFields()
: mA_IM("")
, mAccept("")
, mAcceptCharset("")
, mAcceptEncoding("")
, mAcceptLanguage("")
, mAccessControlRequestHeaders("")
, mAccessControlRequestMethod("")
, mAuthorization("")
, mCacheControl("")
, mConnection("")
, mContentEncoding("")
, mContentLength("")
, mContentType("")
, mCookie("")
, mDate("")
, mExpect("")
, mForwarded("")
, mFrom("")
, mHost("")
, mIfMatch("")
, mIfModifiedSince("")
, mIfNoneMatch("")
, mIfRange("")
, mIfUnmodifiedSince("")
, mMaxForwards("")
, mOrigin("")
, mPragma("")
, mPrefer("")
, mProxyAuthorization("")
, mRange("")
, mReferer("")
, mTE("")
, mTrailer("")
, mTransferEncoding("")
, mUpgrade("")
, mUserAgent("")
, mVia("")
{
}
RequestHeaderFields::~RequestHeaderFields()
{
}
void RequestHeaderFields::parseRequestHeaderFields(const std::string& fields)
{
    (void)fields;
}
const std::string& RequestHeaderFields::getA_IM() const
{
    return mA_IM;
}
const std::string& RequestHeaderFields::getAccept() const
{
    return mAccept;
}
const std::string& RequestHeaderFields::getAcceptCharset() const
{
    return mAcceptCharset;
}
const std::string& RequestHeaderFields::getAcceptEncoding() const
{
    return mAcceptEncoding;
}
const std::string& RequestHeaderFields::getAcceptLanguage() const
{
    return mAcceptLanguage;
}
const std::string& RequestHeaderFields::getAccessControlRequestMethod() const
{
    return mAccessControlRequestMethod;
}
const std::string& RequestHeaderFields::getAccessControlRequestHeaders() const
{
    return mAccessControlRequestHeaders;
}
const std::string& RequestHeaderFields::getAuthorization() const
{
    return mAuthorization;
}
const std::string& RequestHeaderFields::getCacheControl() const
{
    return mCacheControl;
}
const std::string& RequestHeaderFields::getConnection() const
{
    return mConnection;
}
const std::string& RequestHeaderFields::getContentEncoding() const
{
    return mContentEncoding;
}
const std::string& RequestHeaderFields::getContentLength() const
{
    return mContentLength;
}
const std::string& RequestHeaderFields::getContentType() const
{
    return mContentType;
}
const std::string& RequestHeaderFields::getCookie() const
{
    return mCookie;
}
const std::string& RequestHeaderFields::getDate() const
{
    return mDate;
}
const std::string& RequestHeaderFields::getExpect() const
{
    return mExpect;
}
const std::string& RequestHeaderFields::getForwarded() const
{
    return mForwarded;
}
const std::string& RequestHeaderFields::getFrom() const
{
    return mFrom;
}
const std::string& RequestHeaderFields::getHost() const
{
    return mHost;
}
const std::string& RequestHeaderFields::getIfMatch() const
{
    return mIfMatch;
}
const std::string& RequestHeaderFields::getIfModifiedSince() const
{
    return mIfModifiedSince;
}
const std::string& RequestHeaderFields::getIfNoneMatch() const
{
    return mIfNoneMatch;
}
const std::string& RequestHeaderFields::getIfRange() const
{
    return mIfRange;
}
const std::string& RequestHeaderFields::getIfUnmodifiedSince() const
{
    return mIfUnmodifiedSince;
}
const std::string& RequestHeaderFields::getMaxForwards() const
{
    return mMaxForwards;
}
const std::string& RequestHeaderFields::getOrigin() const
{
    return mOrigin;
}
const std::string& RequestHeaderFields::getPragma() const
{
    return mPragma;
}
const std::string& RequestHeaderFields::getPrefer() const
{
    return mPrefer;
}
const std::string& RequestHeaderFields::getProxyAuthorization() const
{
    return mProxyAuthorization;
}
const std::string& RequestHeaderFields::getRange() const
{
    return mRange;
}
const std::string& RequestHeaderFields::getReferer() const
{
    return mReferer;
}
const std::string& RequestHeaderFields::getTE() const
{
    return mTE;
}
const std::string& RequestHeaderFields::getTrailer() const
{
    return mTrailer;
}
const std::string& RequestHeaderFields::getTransferEncoding() const
{
    return mTransferEncoding;
}
const std::string& RequestHeaderFields::getUpgrade() const
{
    return mUpgrade;
}
const std::string& RequestHeaderFields::getUserAgent() const
{
    return mUserAgent;
}
const std::string& RequestHeaderFields::getVia() const
{
    return mVia;
}
