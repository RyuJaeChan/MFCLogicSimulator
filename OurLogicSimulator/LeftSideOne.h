#pragma once
#include "afxcmn.h"



// CLeftSideOne 폼 뷰입니다.

class CLeftSideOne : public CFormView
{
	DECLARE_DYNCREATE(CLeftSideOne)

protected:
	CLeftSideOne();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CLeftSideOne();

public:
	enum { IDD = IDD_LEFTSIDEONE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_treeCtrl;
	CImageList m_imageList;
	virtual void OnInitialUpdate();
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
};


