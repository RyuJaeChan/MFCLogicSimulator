#include "stdafx.h"
#include "Gate.h"


Gate::Gate()
{

}


Gate::~Gate()
{
}

void Gate::PrintGate(CPoint point, CClientDC* dc){
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_ANDGATE);
	CDC dcmem;
	dcmem.CreateCompatibleDC(dc);
	dcmem.SelectObject(&bitmap);
	
	dc->Rectangle(point.x-5, point.y-5, point.x + 5, point.y + 5);
	dc->Rectangle(point.x - this->width-5, point.y - this->height / 2 + this->height / 3-5, point.x - this->width+5, point.y - this->height / 2 + this->height / 3+5);
	dc->Rectangle(point.x - this->width - 5, point.y + this->height / 2 - this->height / 3 - 5, point.x - this->width + 5, point.y + this->height / 2 - this->height / 3 + 5);
	dc->BitBlt(point.x - this->width, point.y - this->height / 2, point.x, point.y, &dcmem, 0, 0, SRCCOPY);
}