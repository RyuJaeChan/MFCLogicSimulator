
// OurLogicSimulatorView.cpp : COurLogicSimulatorView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// COurLogicSimulatorView 생성/소멸
bool isDrawline =false;
bool isCreate = false;
CPoint from;
COurLogicSimulatorView::COurLogicSimulatorView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

COurLogicSimulatorView::~COurLogicSimulatorView()
{
}

BOOL COurLogicSimulatorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// COurLogicSimulatorView 그리기

void COurLogicSimulatorView::OnDraw(CDC* pDC)
{
	COurLogicSimulatorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	Gate temp;
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
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


// COurLogicSimulatorView 진단

#ifdef _DEBUG
void COurLogicSimulatorView::AssertValid() const
{
	CView::AssertValid();
}

void COurLogicSimulatorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COurLogicSimulatorDoc* COurLogicSimulatorView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COurLogicSimulatorDoc)));
	return (COurLogicSimulatorDoc*)m_pDocument;
}
#endif //_DEBUG


// COurLogicSimulatorView 메시지 처리기


void COurLogicSimulatorView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	CView::OnMouseMove(nFlags, point);
//	
//}


void COurLogicSimulatorView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar == VK_RETURN){
		isCreate = true;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
