#pragma once
#include "pbext.h"

class pbadd: 
	public IPBX_NonVisualObject
{
public:   
	pbadd();   
	virtual ~pbadd();   
	PBXRESULT Invoke(      
		IPB_Session   *session,      
		pbobject      obj,      
		pbmethodID    mid,      
		PBCallInfo    *ci);    
	int f_add(IPB_Session*, pbint, pbint);
	// Enum used to provide entry points for each
	// method in the class - the only one in this case
	// is mAdd   
	enum MethodIDs   
	{     
		mAdd = 0    
	};
private:   
	virtual void Destroy();
};