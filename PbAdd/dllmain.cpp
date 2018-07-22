// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "pbadd.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

// describe the pbadd class
PBXEXPORT LPCTSTR PBXCALL PBX_GetDescription()
{
	static const TCHAR desc[] = {
		_T("class pbadd from nonvisualobject \n") \
		_T("function int f_add(int a,int b)\n") \
		_T("end class \n")
	};
	return desc;
}

// export the required PBX_CreateNonVisualObject
// function so that the PBVM can
// create an instance of the class
PBXEXPORT PBXRESULT PBXCALL PBX_CreateNonVisualObject
(
	IPB_Session*    pbSession,
	pbobject        pbobj,
	LPCSTR          xtraName,
	IPBX_NonVisualObject   **obj
)
{
	// if the calling function requests the pbadd   
	// class, create an instance   
	if (strcmp(xtraName, "pbadd") == 0)
	{
		*obj = new pbadd;
	}
	return 0;
};
