#include "stdafx.h"
#include "Gate.h"


Gate::Gate()
{

}


Gate::~Gate()
{
}

void Gate::PrintGate(CPoint point, CDC* dc ,int gateNum){
	CBitmap bitmap;
	int gateN;
	switch (gateNum){
	case 1: gateN = IDB_ANDGATE;
		break;
	case 2: gateN = IDB_ORGATE;
		break;
	default: break;
	}
	bitmap.LoadBitmapW(gateN);
	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);
	GateDotSet temp;
	point.x /= 10;
	point.y /= 10;
	point.x *= 10;
	point.y *= 10;
	CBrush brush(RGB(100, 100, 222));
	dc->SelectObject(&brush);
	dc->BitBlt(point.x - this->width, point.y - this->height / 2, point.x, point.y, &dcmem, 0, 0, SRCCOPY);
	dc->Ellipse(point.x-4, point.y-4, point.x + 4, point.y + 4);
	dc->Ellipse(point.x - this->width-4, point.y - this->height / 2 + this->height / 3-4, point.x - this->width+4, point.y - this->height / 2 + this->height / 3+4);
	dc->Ellipse(point.x - this->width - 4, point.y + this->height / 2 - this->height / 3 - 4, point.x - this->width + 4, point.y + this->height / 2 - this->height / 3 + 4);
	
	temp.first_in = CRect(point.x - 2, point.y - 2, point.x + 2, point.y + 2);
	temp.second_in = CRect(point.x - this->width - 2, point.y - this->height / 2 + this->height / 3 - 2, point.x - this->width + 2, point.y - this->height / 2 + this->height / 3 + 2);
	temp.out = CRect(point.x - this->width - 2, point.y + this->height / 2 - this->height / 3 - 2, point.x - this->width + 2, point.y + this->height / 2 - this->height / 3 + 2);
	gateArr.Add(temp);
}

BOOL SearchDot(CPoint& point, CPoint& in){
	for (int i = 0; i < gateArr.GetSize(); i++){
		if (PtInRect(gateArr[i].first_in, point)){
			in= gateArr[i].first_in.CenterPoint();
			return TRUE;
		}
		else if (PtInRect(gateArr[i].second_in, point)){
			in= gateArr[i].second_in.CenterPoint();
			return TRUE;
		}
		else if (PtInRect(gateArr[i].out, point)){
			in= gateArr[i].out.CenterPoint();
			return TRUE;
		}
	}
	return NULL;
}
void Lining(CPoint point){
	
}