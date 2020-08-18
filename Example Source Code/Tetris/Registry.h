//	Registry.h - Bubbles for Pocket PC (registry support)
//
//	Copyright (C) 2000-2004 Ramon de Klein (Ramon.de.Klein@ict.nl)
//
//	This program is free software; you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation; either version 2 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program; if not, write to the Free Software
//	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#ifndef __REGISTRY_H
#define __REGISTRY_H


class CRegistry
{
// Construction
public:
	CRegistry();
	virtual ~CRegistry();

// Operations
public:
	virtual bool Open  (HKEY hkeyRoot, LPCTSTR pszPath, bool fCreate);
	virtual bool Close (void);

	virtual bool GetLength (LPCTSTR pszKey, DWORD& dwLength);

	virtual bool Write (LPCTSTR pszKey, DWORD dwVal);
	virtual bool Write (LPCTSTR pszKey, LPCTSTR pszVal);
	virtual bool Write (LPCTSTR pszKey, const LPBYTE pbData, DWORD dwLength);

	virtual bool Read (LPCTSTR pszKey, DWORD& dwVal);
	virtual bool Read (LPCTSTR pszKey, LPTSTR pszData, DWORD dwLength);
	virtual bool Read (LPCTSTR pszKey, LPBYTE pbData, DWORD dwLength);

	virtual bool DeleteKey (LPCTSTR pszSubkey = 0);
	virtual bool DeleteValue (LPCTSTR pszValue);

	virtual bool EnumerateKey (DWORD dwIndex, LPTSTR lpName, DWORD dwNameLength);
	virtual bool EnumerateValue (DWORD dwIndex, LPTSTR lpName, DWORD dwNameLength, DWORD& dwType);

// Attributes
protected:
	HKEY	m_hkey;				// Currently opened key
	LPTSTR	m_pszPath;			// Path to the registry entry
};


inline
CRegistry::CRegistry()
	: m_hkey(0)
	, m_pszPath(0)
{
}

inline
CRegistry::~CRegistry()
{
	// Close the key if necessary
	if (m_hkey)
	{
		// Perform an implicit close
		Close();
	}
}

inline
bool CRegistry::Open (HKEY hkeyRoot, LPCTSTR pszPath, bool fCreate)
{
	// Check parameters
	ATLASSERT(hkeyRoot);
	ATLASSERT(pszPath);

	// Check if the key is already opened
	ATLASSERT(m_hkey == 0);
	ATLASSERT(m_pszPath == 0);

	// Use a local error status, because we don't want to
	// overwrite the last error status in the "finally"
	// block, which could call "Disconnect".
	LONG lLastError = ERROR_SUCCESS;

	// Create or open the specified registry key
	if (fCreate)
	{
		DWORD dwDummy;
		lLastError = ::RegCreateKeyEx(
			hkeyRoot,
			pszPath,
			0,
			0,
			REG_OPTION_NON_VOLATILE, 
			KEY_ALL_ACCESS,
			0,
			&m_hkey,
			&dwDummy);
	}
	else
	{
		// [NOTE:]
		// Windows 95/98 cannot open registry keys which end with
		// a trailing slash, so make sure it's not there.
		ATLASSERT(pszPath[_tcslen(pszPath)-1] != _T('\\'));

		lLastError = ::RegOpenKeyEx(
			hkeyRoot,			// Handle of open key
			pszPath,			// Address of name of subkey to open
			0,					// Reserved
			KEY_ALL_ACCESS,		// Security access mask
			&m_hkey);			// Address of handle of open key
	}

	// Check if the registry was succesfully opened
	if (lLastError != ERROR_SUCCESS)
		return false;

	// Save the pathname
 	m_pszPath = new TCHAR[_tcslen(pszPath)+1];
	lstrcpy(m_pszPath,pszPath);

	// Registry successfully opened
	return true;
}

inline
bool CRegistry::Close()
{
	// Check if the registry was opened
	if (m_hkey)
	{
		// Free the pathname
		delete[] m_pszPath;
		m_pszPath = 0;

		// Try to close the registry key
		LONG lLastError = ::RegCloseKey(m_hkey);
		m_hkey = 0;

		if (lLastError != ERROR_SUCCESS)
			return false;
	}

	return true;
}

inline
bool CRegistry::GetLength (LPCTSTR pszKey, DWORD& dwLength)
{
	// Make sure we're connected and a key has been specified
	ATLASSERT(m_hkey);
	ATLASSERT(pszKey);

	// Get the value length
	LONG lLastError = ::RegQueryValueEx(
		m_hkey,					// Registry key handle
		pszKey,					// Name of the value
		0,						// Reserved
		NULL,					// Value type
		NULL,					// Address of value data	
		&dwLength);				// Size of value data

	// Check if the was closed successfully
	if (lLastError != ERROR_SUCCESS)
		return false;

	// Registry successfully read
	return true;
}

inline
bool CRegistry::Write (LPCTSTR pszKey, DWORD dwVal)
{
	// Make sure we're connected and a key has been specified
	ATLASSERT(m_hkey);
	ATLASSERT(pszKey);

	// Set the value
	LONG lLastError = ::RegSetValueEx(
		m_hkey,					// Registry key handle
		pszKey,					// Name of the value
		0,						// Reserved
		REG_DWORD,				// Value type
		(CONST LPBYTE) &dwVal,	// Address of value data	
		sizeof(DWORD));			// Size of value data

	// Check if the was closed successfully
	if (lLastError != ERROR_SUCCESS)
		return false;

	// Registry successfully written
	return true;
}

inline
bool CRegistry::Write (LPCTSTR pszKey, LPCTSTR pszData)
{
	// Make sure we're connected and a key has been specified
	ATLASSERT(m_hkey);
	ATLASSERT(pszKey);
	ATLASSERT(pszData);

	// Set the value
	LONG lLastError = ::RegSetValueEx(
		m_hkey,					// Registry key handle
		pszKey,					// Name of the value
		0,						// Reserved
		REG_SZ,					// Value type
		(CONST LPBYTE) pszData,	// Address of value data	
		(_tcslen(pszData)+1)*sizeof(TCHAR));
								// Size of value data

	// Check if the was closed successfully
	if (lLastError != ERROR_SUCCESS)
		return false;

	// Registry successfully written
	return true;
}

inline
bool CRegistry::Write (LPCTSTR pszKey, const LPBYTE pbData, DWORD dwLength)
{
	// Make sure we're connected and a key has been specified
	ATLASSERT(m_hkey);
	ATLASSERT(pszKey);
	ATLASSERT(pbData && dwLength>0);

	// Set the value
	LONG lLastError = ::RegSetValueEx(
		m_hkey,					// Registry key handle
		pszKey,					// Name of the value
		0,						// Reserved
		REG_BINARY,				// Value type
		(CONST LPBYTE) pbData,	// Address of value data	
		dwLength);				// Size of value data

	// Check if the was closed successfully
	if (lLastError != ERROR_SUCCESS)
		return false;

	// Registry successfully written
	return true;
}

inline
bool CRegistry::DeleteKey (LPCTSTR pszSubkey)
{
	// Make sure we're connected and a key has been specified
	ATLASSERT(m_hkey);

	// If no key is specified then the current key must be used
	if (pszSubkey == 0)
		pszSubkey = _T("");

	// Set the value
	LONG lLastError = ::RegDeleteKey(
		m_hkey,					// Registry key handle
		pszSubkey);				// Name of the value

	// Check if the key was deleted successfully
	if (lLastError != ERROR_SUCCESS)
		return false;

	// Key successfully deleted
	return true;
}

inline
bool CRegistry::DeleteValue (LPCTSTR pszValue)
{
	// Make sure we're connected and a key has been specified
	ATLASSERT(m_hkey);
	ATLASSERT(pszValue);

	// Set the value
	LONG lLastError = ::RegDeleteValue(
		m_hkey,					// Registry key handle
		pszValue);				// Name of the value

	// Check if the value was deleted successfully
	if (lLastError != ERROR_SUCCESS)
		return false;

	// Value successfully deleted
	return true;
}

inline
bool CRegistry::Read (LPCTSTR pszKey, DWORD& dwVal)
{
	// Make sure we're connected and a key has been specified
	ATLASSERT(m_hkey);
	ATLASSERT(pszKey);

	// Get the value
	DWORD dwType ;
	DWORD dwLength = sizeof(dwVal);
	LONG lLastError = ::RegQueryValueEx(
		m_hkey,					// Registry key handle
		pszKey,					// Name of the value
		0,						// Reserved
		&dwType,				// Value type
		(LPBYTE) &dwVal,		// Address of value data	
		&dwLength);				// Size of value data

	// Check if the type was correct
	if ((dwType != REG_DWORD) || lLastError != ERROR_SUCCESS)
		return false;

	// Registry successfully read
	return true;
}

inline
bool CRegistry::Read (LPCTSTR pszKey, LPTSTR pszData, DWORD dwLength)
{
	// Make sure we're connected and a key has been specified
	ATLASSERT(m_hkey);
	ATLASSERT(pszKey);
	ATLASSERT(pszData && dwLength>0);

	// Make sure there is enough room to store the name
	ATLASSERT(!::IsBadWritePtr(pszData,dwLength));

	// Get the value
	DWORD dwType;
	LONG lLastError = ::RegQueryValueEx(
		m_hkey,					// Registry key handle
		pszKey,					// Name of the value
		0,						// Reserved
		&dwType,				// Value type
		(LPBYTE) pszData,		// Address of value data	
		&dwLength);				// Size of value data

	// Check if the type was correct
	if ((dwType != REG_SZ) || lLastError != ERROR_SUCCESS)
		return false;
	
	// Registry successfully read
	return true;
}

inline
bool CRegistry::Read (LPCTSTR pszKey, LPBYTE pbData, DWORD dwLength)
{
	// Make sure we're connected and a key has been specified
	ATLASSERT(m_hkey);
	ATLASSERT(pszKey);
	ATLASSERT(pbData && dwLength>0);

	// Make sure there is enough room to store the name
	ATLASSERT(!::IsBadWritePtr(pbData,dwLength));

	// Get the value
	DWORD dwType;
	LONG lLastError = ::RegQueryValueEx(
		m_hkey,					// Registry key handle
		pszKey,					// Name of the value
		0,						// Reserved
		&dwType,				// Value type
		(LPBYTE) pbData,		// Address of value data	
		&dwLength);				// Size of value data

	// Check if the type was correct
	if ((dwType != REG_BINARY) || lLastError != ERROR_SUCCESS)
		return false;

	// Registry successfully read
	return true;
}

inline
bool CRegistry::EnumerateKey (DWORD dwIndex, LPTSTR lpName, DWORD dwNameLength)
{
	// Make sure we're connected and a name has been specified
	ATLASSERT(m_hkey);
	ATLASSERT(lpName);
	ATLASSERT(dwNameLength>0);

	// Make sure there is enough room to store the name
	ATLASSERT(!::IsBadWritePtr(lpName,dwNameLength));

	// Call the Win32 API function to store the data
	LONG lLastError = ::RegEnumKeyEx(
		m_hkey,					// Handle of key to enumerate
		dwIndex,				// Index of subkey to enumerate
		lpName,					// Address of buffer for subkey name
		&dwNameLength,			// Address for size of subkey buffer
		0,	 					// Reserved (should be 0)
		0,						// Address of buffer for class string
		0,						// Address for size of class buffer
		0);						// Address for time key last written to

	// Check if the registry was succesfully enumerated
	if (lLastError != ERROR_SUCCESS)
		return false;

	// We've successfully enumerated the registry
	return true;
}

inline
bool CRegistry::EnumerateValue (DWORD dwIndex, LPTSTR lpName, DWORD dwNameLength, DWORD& dwType)
{
	// Make sure we're connected and a name has been specified
	ATLASSERT(m_hkey);
	ATLASSERT(lpName);
	ATLASSERT(dwNameLength>0);

	// Make sure there is enough room to store the name
	ATLASSERT(!::IsBadWritePtr(lpName,dwNameLength));

	// Call the Win32 API function to store the data
	LONG lLastError = ::RegEnumValue(
		m_hkey,					// Handle of key to enumerate
		dwIndex,				// Index of value to enumerate
		lpName,					// Address of buffer for value name
		&dwNameLength,			// Address for size of value buffer
		NULL,					// Reserved (should be NULL)
		&dwType,				// Address of buffer for type code
		NULL,					// Address of buffer for value data
		0);						// Address for size of data buffer

	// Check if the registry was succesfully enumerated
	if (lLastError != ERROR_SUCCESS)
		return false;

	// We've successfully enumerated the registry
	return true;
}

#endif	// __REGISTRY_H
