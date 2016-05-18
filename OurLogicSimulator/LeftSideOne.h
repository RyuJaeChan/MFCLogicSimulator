#pragma once


// CLeftSideOne 뷰입니다.

class CLeftSideOne : public CTreeView
{
	DECLARE_DYNCREATE(CLeftSideOne)

protected:
	CLeftSideOne();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CLeftSideOne();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	CImageList m_imageList;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTvnSelchanging(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


