// LeftSideOne.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "OurLogicSimulator.h"
#include "LeftSideOne.h"
#include "OurLogicSimulatorDoc.h"
#include "Gate.h"							////
#include "MainFrm.h"



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


// CLeftSideOne 진단입니다.

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


// CLeftSideOne 메시지 처리기입니다.


void CLeftSideOne::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	m_imageList.Create(16, 16, ILC_COLOR8, 10, 10);
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_DIR));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_AND));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_OR));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_NOT));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_NAND));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_NOR));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_XOR));

	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_D_FF));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_T_FF));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_JK_FF));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_LIB));
	m_imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_LIB_CHECKED));



	m_treeCtrl.SetImageList(&m_imageList, TVSIL_NORMAL);

	HTREEITEM  hRoot, hGate, hMemory, hChild;

	hRoot = m_treeCtrl.InsertItem(L"ROOT", 0, 0, TVI_ROOT, TVI_LAST);

	hGate = m_treeCtrl.InsertItem(L"Gates", 0, 0, hRoot, TVI_LAST);
	hChild = m_treeCtrl.InsertItem(L"AND", 1, 1, hGate, TVI_LAST);
	m_treeCtrl.SetItemData(hChild, 1);
	hChild = m_treeCtrl.InsertItem(L"OR", 2, 2, hGate, TVI_LAST);
	m_treeCtrl.SetItemData(hChild, 2);
	hChild = m_treeCtrl.InsertItem(L"NOT", 3, 3, hGate, TVI_LAST);
	m_treeCtrl.SetItemData(hChild, 3);
	hChild = m_treeCtrl.InsertItem(L"NAND", 4, 4, hGate, TVI_LAST);
	m_treeCtrl.SetItemData(hChild, 4);
	hChild = m_treeCtrl.InsertItem(L"NOR", 5, 5, hGate, TVI_LAST);
	m_treeCtrl.SetItemData(hChild, 5);
	hChild = m_treeCtrl.InsertItem(L"XOR", 6, 6, hGate, TVI_LAST);
	m_treeCtrl.SetItemData(hChild, 6);


	hMemory = m_treeCtrl.InsertItem(L"Memory", 0, 0, hRoot, TVI_LAST);
	hChild = m_treeCtrl.InsertItem(L"D Flip-Flop", 7, 7, hMemory, TVI_LAST);
	m_treeCtrl.SetItemData(hChild, 7);
	hChild = m_treeCtrl.InsertItem(L"T Flip-Flop", 8, 8, hMemory, TVI_LAST);
	m_treeCtrl.SetItemData(hChild, 8);
	hChild = m_treeCtrl.InsertItem(L"JK Flip-Flop", 9, 9, hMemory, TVI_LAST);
	m_treeCtrl.SetItemData(hChild, 9);

	m_treeCtrl.Expand(hRoot, TVE_EXPAND);
	m_treeCtrl.Expand(hGate, TVE_EXPAND);
	m_treeCtrl.Expand(hMemory, TVE_EXPAND);		//펼치기

	ResizeParentToFit(TRUE);


	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


void CLeftSideOne::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	

	HTREEITEM hItem = m_treeCtrl.GetSelectedItem();
	
	CString str = m_treeCtrl.GetItemText(hItem);
	
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	pFrame->m_pMainView->isCreate = m_treeCtrl.GetItemData(pNMTreeView->itemNew.hItem);
	pFrame->m_pMainView->gateNum = m_treeCtrl.GetItemData(pNMTreeView->itemNew.hItem);
	*pResult = 0;
}
