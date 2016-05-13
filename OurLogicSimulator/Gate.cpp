#include "stdafx.h"
#include "Gate.h"


Gate::Gate()
{

}


Gate::~Gate()
{
}

void Gate::PrintGate(CPoint point, CDC* dc){
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_ANDGATE);
	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);
	GateDotSet temp;
	dc->Rectangle(point.x-5, point.y-5, point.x + 5, point.y + 5);
	dc->Rectangle(point.x - this->width-5, point.y - this->height / 2 + this->height / 3-5, point.x - this->width+5, point.y - this->height / 2 + this->height / 3+5);
	dc->Rectangle(point.x - this->width - 5, point.y + this->height / 2 - this->height / 3 - 5, point.x - this->width + 5, point.y + this->height / 2 - this->height / 3 + 5);
	dc->BitBlt(point.x - this->width, point.y - this->height / 2, point.x, point.y, &dcmem, 0, 0, SRCCOPY);
	temp.first_in = CRect(point.x - 5, point.y - 5, point.x + 5, point.y + 5);
	temp.second_in = CRect(point.x - this->width - 5, point.y - this->height / 2 + this->height / 3 - 5, point.x - this->width + 5, point.y - this->height / 2 + this->height / 3 + 5);
	temp.out = CRect(point.x - this->width - 5, point.y + this->height / 2 - this->height / 3 - 5, point.x - this->width + 5, point.y + this->height / 2 - this->height / 3 + 5);
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