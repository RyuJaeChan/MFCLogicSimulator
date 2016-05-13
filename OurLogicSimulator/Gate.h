#pragma once
#include "Resource.h"
class Gate
{
private: 
	int width =50;
	int height =50;
public :
	void PrintGate(CPoint point, CClientDC* dc); 
	
public:
	Gate();
	~Gate();
};
struct GateDotSet{
	CRect first_in;
	CRect second_in;
	CRect out;
};
static CArray<GateDotSet, GateDotSet&> gateArr;
BOOL SearchDot(CPoint& point, CPoint& in);
void Lining(CPoint point);
