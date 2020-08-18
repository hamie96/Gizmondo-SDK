/*++
Copyright (c) Microsoft Corporation

Module Name:   majfactory.h

Abstract:  
    Global Class Factory implementation
Functions:


Notes: 

--*/
#ifndef _MAJFACTORY_H_
#define _MAJFACTORY_H_

#ifdef __cplusplus

typedef HRESULT (*PFNCREATE)(IUnknown *pUnkOuter, REFIID riid, LPVOID *ppv);

typedef struct _OBJCREATETABLE
{
    const CLSID *pClsID;
    PFNCREATE pfnCreate;
} OBJCREATETABLE, *POBJCREATETABLE;


class CClassFactory
{
public:
    // IUnknown Methods
    STDMETHOD  (QueryInterface)(REFIID riid, void **ppv)
    {
        if ((riid == IID_IUnknown) || (riid == IID_IClassFactory))
        {
            *ppv = this;
            return S_OK;
        }
        else
        {
            return E_NOINTERFACE;
        }
    }

    STDMETHOD_ (ULONG, AddRef)(void)
    {
        return InterlockedIncrement(&m_lRefCount);
    }

    STDMETHOD_ (ULONG, Release)(void)
    {
        ASSERT(m_lRefCount);

        LONG rc = InterlockedDecrement(&m_lRefCount);

        if (rc == 0)
        {
            delete(this);
        }

        return rc;
    }

    // IClassFactory Methods
    STDMETHOD  (CreateInstance)(IUnknown *pUnkOuter, REFIID riid, LPVOID *ppv)
    {
        return m_pfnCreate(pUnkOuter, riid, ppv);
    }

    STDMETHOD  (LockServer)(BOOL bLock)
    {
        return S_OK;
    }

    CClassFactory(PFNCREATE pfnCreate)
    {
        m_pfnCreate = pfnCreate;
        m_lRefCount = 1;
    }

    ~CClassFactory() { };

private:
    PFNCREATE m_pfnCreate;
    LONG      m_lRefCount;
};

#endif  // __cplusplus

#endif  // _MAJFACTORY_H_

