#pragma once
#include "afxcmn.h"



// CLeftSideOne �� ���Դϴ�.

class CLeftSideOne : public CFormView
{
	DECLARE_DYNCREATE(CLeftSideOne)

protected:
	CLeftSideOne();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_treeCtrl;
	virtual void OnInitialUpdate();
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
};


