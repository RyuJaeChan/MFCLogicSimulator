#pragma once
#include "Resource.h"
class Gate
{
private: 
	int width =50;
	int height =50;
public :
	void PrintGate(CPoint point , CClientDC* dc);
public:
	Gate();
	~Gate();
};

