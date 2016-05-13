
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
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// COurLogicSimulatorView ����/�Ҹ�
bool isDrawline =false;
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
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

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
	CPoint temp; ;
	if (SearchDot(point, temp)){
		CPen myPen(PS_SOLID, 2, RGB(100, 200, 200));
		dc.SelectStockObject(NULL_BRUSH);
		dc.SelectObject(&myPen);
		dc.Ellipse(temp.x - 8, temp.y - 8, temp.x + 8, temp.y + 8);
		isDrawline = true;
		from = CPoint(temp.x+4,temp.y);
	}
	else{
		gt.PrintGate(point, &dc);
	}

	////	// TEST


	CView::OnLButtonDown(nFlags, point);
}


void COurLogicSimulatorView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	if (SearchDot(point, CPoint())!=NULL){
		::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
	}
	if (isDrawline){
	}
	CView::OnMouseMove(nFlags, point);
}


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
