// LeftSideOne.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "OurLogicSimulator.h"
#include "LeftSideOne.h"


// CLeftSideOne

IMPLEMENT_DYNCREATE(CLeftSideOne, CFormView)

CLeftSideOne::CLeftSideOne()
	: CFormView(CLeftSideOne::IDD)
{

}

CLeftSideOne::~CLeftSideOne()
{
}

void CLeftSideOne::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLeftSideOne, CFormView)
END_MESSAGE_MAP()


// CLeftSideOne �����Դϴ�.

#ifdef _DEBUG
void CLeftSideOne::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftSideOne::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftSideOne �޽��� ó�����Դϴ�.
