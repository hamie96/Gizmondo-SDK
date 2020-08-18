#ifndef _CEPUBSUBPS_H_
#define _CEPUBSUBPS_H_

interface ISubscriber : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Write(
            DWORD dwBufSize,
            BYTE *pbData) = 0;

    virtual HRESULT STDMETHODCALLTYPE Notify(
            DWORD dwEventCode,
            DWORD dwFlags) = 0;
};

interface IPublisher : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Control(
            DWORD dwControl,
            DWORD dwBufSize,
            BYTE *pbData) = 0;
};

interface IPublisherManagement : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Initialize(
            ISubscriber *pSubscriber,
            BOOL *bUseBuffering,
            DWORD *pdwBufSize) = 0;

    virtual HRESULT STDMETHODCALLTYPE StopPublishing(void) = 0;
    virtual HRESULT STDMETHODCALLTYPE StartPublishing(void) = 0;
};

interface IPublishSubscribeMgr : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Subscribe(
        GUID PlatformID,
        GUID DeviceID,
        GUID PublisherID,
        ISubscriber *pSubscriber,
        IPublisher **ppPublisher,
        GUID *pCookieID) = 0;

    virtual HRESULT STDMETHODCALLTYPE Unsubscribe(GUID cookieID) = 0;
};

extern "C"{
extern const IID IID_ISubscriber;
extern const IID IID_IPublisher;
extern const IID IID_IPublisherManagement;
extern const IID IID_IPublishSubscribeMgr;
extern const IID LIBID_PUBSUBLib;
extern const CLSID CLSID_PublishSubscribeMgr;
}

#endif // _CEPUBSUBPS_H_
