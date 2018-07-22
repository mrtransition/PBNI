// PbAdd.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h" 
#include "pbadd.h" 

// Implement the required Invoke method
PBXRESULT pbadd:: Invoke(IPB_Session *Session,   
	pbobject obj, pbmethodID mid, PBCallInfo *ci)
{   
	// if the method to call is f_add   
	if (mid == mAdd)   
	{      
		int sum = f_add(Session, 
			ci->pArgs->GetAt(0)->GetInt(), 
			ci->pArgs->GetAt(1)->GetInt()
				);      
		ci->returnValue->SetInt(sum);   
	}   
	return PBX_OK;
}
// constructor and destructor
pbadd:: pbadd()
{
}
pbadd:: ~pbadd()
{
}

// implement the class's f_add method
int pbadd:: f_add(IPB_Session* session,pbint arg1,pbint arg2)
{   
	return arg1 + arg2;
} 

// Implement the required Destroy method
void pbadd::Destroy()
{   
	delete this;
}