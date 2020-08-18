#ifndef _DBCSUTIL_H_
#define _DBCSUTIL_H_
inline DWORD WideLen( LPCWSTR pszText) 
{
	return( WideCharToMultiByte( GetACP(),  0, pszText, -1, NULL, 0, NULL, NULL)+1);
}

inline DWORD MBLen( LPCTSTR pszText)
{
	return( MultiByteToWideChar( GetACP(),  0, pszText, -1, NULL, 0)+1);
}

inline void wide2tchar( LPTSTR pszStr1, LPCOLESTR pszStr2)
{
#ifdef _UNICODE
	wcscpy( pszStr1, pszStr2);
#else
//	wcstombs( pszStr1, pszStr2, WideLen(pszStr2)+1);
	WideCharToMultiByte( GetACP(),  0, pszStr2, -1, pszStr1, WideLen(pszStr2), NULL, NULL);
#endif
}


inline void tchar2wide( LPOLESTR pszStr1, LPTSTR pszStr2)
{
#ifdef _UNICODE
	wcscpy( pszStr1, pszStr2);
#else
	MultiByteToWideChar( GetACP(),  0, pszStr2, -1, pszStr1, MBLen(pszStr2));
#endif
}
#endif