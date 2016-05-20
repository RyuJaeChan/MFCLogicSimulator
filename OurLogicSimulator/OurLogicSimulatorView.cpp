
// OurLogicSimulatorView.cpp : COurLogicSimulatorView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "OurLogicSimulator.h"
#endif
#include "Gate.h"
#include "OurLogicSimulatorDoc.h"
#include "OurLogicSimulatorView.h"
#include "LeftSideOne.h"
#include<iostream>
#include<vector>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COurLogicSimulatorView

IMPLEMENT_DYNCREATE(COurLogicSimulatorView, CView)

BEGIN_MESSAGE_MAP(COurLogicSimulatorView, CView)
	ON_WM_LBUTTONDOWN()
//	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// COurLogicSimulatorView ����/�Ҹ�
bool isDrawline =false;
bool isClicked = false;
//bool isCreate = false;
CPoint from;
CPoint to;
int board[1000][1000];
std::vector<std::pair<CPoint, CPoint > >lines;
COurLogicSimulatorView::COurLogicSimulatorView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	lines.assign(1,std::pair<CPoint,CPoint>());
	isCreate = false;
	gateNum = 0;
}

COurLogicSimulatorView::~COurLogicSimulatorView()
{
}

BOOL COurLogicSimulatorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// COurLogicSimulatorView �׸���

void COurLogicSimulatorView::OnDraw(CDC* pDC)
{
	COurLogicSimulatorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	Gate temp;
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CDC mDC;
	CBitmap m_Bitmap;
	CRect rect;
	GetClientRect(&rect);
	mDC.CreateCompatibleDC(pDC);
	m_Bitmap.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	mDC.SelectObject(&m_Bitmap);
	mDC.PatBlt(0, 0, rect.Width(), rect.Height(), WHITENESS);


	// print pre line
	if (isDrawline == true && isClicked == true){
		CPen myPen(PS_SOLID, 2, RGB(200, 200, 200));
		mDC.SelectObject(&myPen);
		mDC.MoveTo(from);
		mDC.LineTo(to.x, from.y);
		mDC.MoveTo(to.x, from.y);
		mDC.LineTo(to);
	}
	// print board
	for (int i = 0; i < 200; i++){
		for (int j = 0; j < 200; j++){
			mDC.SetPixelV(i * 10, j * 10, RGB(0, 0, 0));
		}
	}
	// print gate
	//mDC.SelectStockObject(NULL_PEN);
	for (int i = 0; i < andPoints.GetSize(); i++){
		temp.PrintGate(andPoints[i], &mDC, 1);
	}
	for (int i = 0; i < orPoints.GetSize(); i++){
		temp.PrintGate(orPoints[i], &mDC, 2);
	}
	for (int i = 0; i < notPoints.GetSize(); i++){
		temp.PrintGate(notPoints[i], &mDC, 3);
	}
	//print line
	for (auto it = lines.begin(); it != lines.end(); it++){
		CPen myPen(PS_SOLID, 2, RGB(200, 100, 100));
		mDC.SelectObject(&myPen);
		mDC.MoveTo(it->first);
		mDC.LineTo(it->second.x, it->first.y);
		mDC.MoveTo(it->second.x, it->first.y);
		mDC.LineTo(it->second);
	}
	

	////////////////////////////
	CPoint point;
	::GetCursorPos(&point);
	CPoint pTemp;
	if (SearchDot(point, pTemp)){
		CPen myPen(PS_SOLID, 2, RGB(100, 200, 200));
		mDC.SelectStockObject(NULL_BRUSH);
		mDC.SelectObject(&myPen);
		mDC.Ellipse(pTemp.x - 8, pTemp.y - 8, pTemp.x + 8, pTemp.y + 8);
	}

	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &mDC, 0, 0, SRCCOPY);
}


// COurLogicSimulatorView ����

#ifdef _DEBUG
void COurLogicSimulatorView::AssertValid() const
{
	CView::AssertValid();
}

void COurLogicSimulatorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COurLogicSimulatorDoc* COurLogicSimulatorView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COurLogicSimulatorDoc)));
	return (COurLogicSimulatorDoc*)m_pDocument;
}
#endif //_DEBUG


// COurLogicSimulatorView �޽��� ó����


void COurLogicSimulatorView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	Gate gt;
	CPoint temp;
	if (SearchDot(point, temp)){
		isDrawline = true;
		from = CPoint(temp.x+4,temp.y);
		isClicked = true;
	}
	else{
		if (isCreate == true){
			switch (gateNum){
			case 1: andPoints.Add(point);
				break;
			case 2: orPoints.Add(point);
				break;
			case 3: notPoints.Add(point);
				break;
			default:
				break;
			}
			isCreate = false;		
			Invalidate();
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void COurLogicSimulatorView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	point.x /= 10;
	point.y /= 10;
	point.x *= 10;
	point.y *= 10;
	to = point;
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (isDrawline){
		lines.push_back(std::pair<CPoint, CPoint>(from, to));
		isDrawline = false;
		Invalidate();
	}
	
	CView::OnLButtonUp(nFlags, point);
}



void COurLogicSimulatorView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nChar == VK_RETURN){
		isCreate = true;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void COurLogicSimulatorView::OnMouseMove(UINT nFlags, CPoint point)
{
	
	point.x /= 10;
	point.y /= 10;
	point.x *= 10;
	point.y *= 10;
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	to = point;
	if (isDrawline){
		Invalidate(false);
	}
	
	CView::OnMouseMove(nFlags, point);
}
