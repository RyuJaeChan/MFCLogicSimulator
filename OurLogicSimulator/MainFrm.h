
// MainFrm.h : CMainFrame 클래스의 인터페이스
//

#pragma once

#include"OurLogicSimulatorDoc.h"
#include"OurLogicSimulatorView.h"
#include"LeftSideOne.h"
#include"LeftSideTwo.h"


class CMainFrame : public CFrameWnd
{
	
protected: // serialization에서만 만들어집니다.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 특성입니다.
public:

// 작업입니다.
public:
	CSplitterWnd			m_MainSplitter;
	CSplitterWnd			m_SubSplitter;

	COurLogicSimulatorView*		m_pMainView;
	CLeftSideOne*				m_pLeftSideOne;
	CLeftSideTwo*				m_pLeftSideTwo;


// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


// 생성된 메시지 맵 함수
protected:
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};


