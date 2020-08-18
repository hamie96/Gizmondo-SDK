#ifndef DOWNLOADERCB_H
#define DOWNLOADERCB_H

// These are the wrappers for the static member function SetBootCB
// in the EthDl.dll library (SetBootCB takes atmost one function CB).
// These wrappers will maintain a list of CB functions and whenever
// EthDl calls into this library, all those callback functions are
// called in-turn

#ifdef __cplusplus
extern "C" {
#endif

BOOL RegisterCB(PFN_BootCB pfnCB, LPVOID pUserData);
BOOL DeRegisterCB(PFN_BootCB pfnCB, LPVOID pUserData);
BOOL LoadCB(LPCWSTR pszDllName);
BOOL UnloadCB();


#ifdef __cplusplus
}
#endif

#endif
