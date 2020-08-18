#ifndef _IGENDATA_H_
#define _IGENDATA_H_


// IID_IGenericData - {A113CB54-7A58-4a8c-A222-D8D10A3431FE}
//DEFINE_GUID(
 //   IID_IGenericData,
  //  0xa113cb54, 0x7a58, 0x4a8c, 0xa2, 0x22, 0xd8, 0xd1, 0xa, 0x34, 0x31, 0xfe
   // );
// {A76B9D9D-B393-441B-8132-0ED5E87F1544}
DEFINE_GUID(
    IID_IGenericData,
	0xA76B9D9D, 0xB393, 0x441B, 0x81, 0x32, 0x0E, 0xD5, 0xE8, 0x7F, 0x15, 0x44
	);

interface IGenericData : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Initialize(
            DWORD dwControlCode) = 0;

    virtual HRESULT STDMETHODCALLTYPE UnInitialize(
            DWORD dwControlCode) = 0;

    virtual HRESULT STDMETHODCALLTYPE SendRecvDwords(
            DWORD dwControlCode,
            DWORD dwIn,
            DWORD *pdwOut) = 0;

    virtual HRESULT STDMETHODCALLTYPE SendRecvBuffers(
            DWORD dwControlCode,
            DWORD dwBufSizeIn,
            BYTE *pbBufIn,
            DWORD *pdwBufSizeOut,
            BYTE **ppbBufOut) = 0;
};

#endif // _IGENDATA_H_
