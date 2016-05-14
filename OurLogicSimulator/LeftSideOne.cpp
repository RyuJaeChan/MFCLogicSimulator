// LeftSideOne.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "OurLogicSimulator.h"
#include "LeftSideOne.h"
#include "Gate.h"



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
	DDX_Control(pDX, IDC_TREE1, m_treeCtrl);
}

BEGIN_MESSAGE_MAP(CLeftSideOne, CFormView)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CLeftSideOne::OnTvnSelchangedTree1)
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


void CLeftSideOne::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	HTREEITEM  hRoot;
	hRoot = m_treeCtrl.InsertItem(L"root", 0, 1, TVI_ROOT, TVI_LAST);
	HTREEITEM  hGate;
	hGate = m_treeCtrl.InsertItem(L"Gates", 1, 1, hRoot, TVI_LAST);
	m_treeCtrl.InsertItem(L"AND", 1, 1, hGate, TVI_LAST);
	m_treeCtrl.InsertItem(L"OR", 1, 1, hGate, TVI_LAST);


	m_treeCtrl.Expand(hRoot, TVE_EXPAND);	//��ġ��
	m_treeCtrl.Expand(hGate, TVE_EXPAND);
	ResizeParentToFit(TRUE);


	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}


void CLeftSideOne::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	

	
	HTREEITEM hItem = m_treeCtrl.GetSelectedItem();
	
	CString str = m_treeCtrl.GetItemText(hItem);
	
	
	
	
	*pResult = 0;
}
