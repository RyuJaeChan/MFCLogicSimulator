
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

// COurLogicSimulatorView 생성/소멸
bool isDrawline =false;
bool isClicked = false;
//bool isCreate = false;
CPoint from;
CPoint to;
int board[1000][1000];
std::vector<std::pair<CPoint, CPoint > >lines;
COurLogicSimulatorView::COurLogicSimulatorView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	lines.assign(1,std::pair<CPoint,CPoint>());
	isCreate = false;
	gateNum = 0;
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
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (isDrawline){
		lines.push_back(std::pair<CPoint, CPoint>(from, to));
		isDrawline = false;
		Invalidate();
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


void COurLogicSimulatorView::OnMouseMove(UINT nFlags, CPoint point)
{
	
	point.x /= 10;
	point.y /= 10;
	point.x *= 10;
	point.y *= 10;
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	to = point;
	if (isDrawline){
		Invalidate(false);
	}
	
	CView::OnMouseMove(nFlags, point);
}
