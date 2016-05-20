#pragma once
#include "Resource.h"

class Gate
{
private:
	int width = 50;
	int height = 50;
public:
	void PrintGate(CPoint point, CDC* dc, int gateNum);
	void SetWidth(int width, int height);
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
static CArray<CPoint, CPoint&> andPoints;
static CArray<CPoint, CPoint&> orPoints;
static CArray<CPoint, CPoint&> notPoints;
BOOL SearchDot(CPoint& point, CPoint& in);
void Lining(CPoint point);