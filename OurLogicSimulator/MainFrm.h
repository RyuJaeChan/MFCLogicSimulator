
// MainFrm.h : CMainFrame Ŭ������ �������̽�
//

#pragma once

#include"OurLogicSimulatorDoc.h"
#include"OurLogicSimulatorView.h"
#include"LeftSideOne.h"
#include"LeftSideTwo.h"


class CMainFrame : public CFrameWnd
{
	
protected: // serialization������ ��������ϴ�.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:
	CSplitterWnd			m_MainSplitter;
	CSplitterWnd			m_SubSplitter;

	COurLogicSimulatorView*		m_pMainView;
	CLeftSideOne*				m_pLeftSideOne;
	CLeftSideTwo*				m_pLeftSideTwo;


// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};


