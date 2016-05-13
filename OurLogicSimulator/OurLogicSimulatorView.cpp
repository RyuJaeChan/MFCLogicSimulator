
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
END_MESSAGE_MAP()

// COurLogicSimulatorView ����/�Ҹ�
bool isDrawline =false;
bool isCreate = false;
CPoint from;
COurLogicSimulatorView::COurLogicSimulatorView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	for (int i = 0; i < andPoints.GetSize(); i++){
		temp.PrintGate(andPoints[i],pDC);
	}
	CPoint point;
	::GetCursorPos(&point);
	CPoint pTemp;
	if (SearchDot(point, pTemp)){
		CPen myPen(PS_SOLID, 2, RGB(100, 200, 200));
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->SelectObject(&myPen);
		pDC->Ellipse(pTemp.x - 8, pTemp.y - 8, pTemp.x + 8, pTemp.y + 8);
	}

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
	}
	else{
		if (isCreate == true){
			andPoints.Add(point);
			Invalidate();
			isCreate = false;
		}
	}

	////	// TEST


	CView::OnLButtonDown(nFlags, point);
}


//void COurLogicSimulatorView::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//	CView::OnMouseMove(nFlags, point);
//	
//}


void COurLogicSimulatorView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (isDrawline){
		CPen myPen(PS_SOLID, 2, RGB(200, 100, 100));
		dc.SelectObject(&myPen);
		dc.MoveTo(from);
		dc.LineTo(point.x, from.y);
		dc.MoveTo(point.x, from.y);
		dc.LineTo(point);
		isDrawline = false;
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
