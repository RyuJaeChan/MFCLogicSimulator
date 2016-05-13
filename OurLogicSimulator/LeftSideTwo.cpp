// LeftSideTwo.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "OurLogicSimulator.h"
#include "LeftSideTwo.h"


// CLeftSideTwo

IMPLEMENT_DYNCREATE(CLeftSideTwo, CFormView)

CLeftSideTwo::CLeftSideTwo()
	: CFormView(CLeftSideTwo::IDD)
{

}

CLeftSideTwo::~CLeftSideTwo()
{
}

void CLeftSideTwo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLeftSideTwo, CFormView)
END_MESSAGE_MAP()


// CLeftSideTwo 진단입니다.

#ifdef _DEBUG
void CLeftSideTwo::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftSideTwo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftSideTwo 메시지 처리기입니다.
