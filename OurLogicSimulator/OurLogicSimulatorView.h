
// OurLogicSimulatorView.h : COurLogicSimulatorView Ŭ������ �������̽�
//

#pragma once


class COurLogicSimulatorView : public CView
{
protected: // serialization������ ��������ϴ�.
	COurLogicSimulatorView();
	DECLARE_DYNCREATE(COurLogicSimulatorView)

// Ư���Դϴ�.
public:
	COurLogicSimulatorDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~COurLogicSimulatorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // OurLogicSimulatorView.cpp�� ����� ����
inline COurLogicSimulatorDoc* COurLogicSimulatorView::GetDocument() const
   { return reinterpret_cast<COurLogicSimulatorDoc*>(m_pDocument); }
#endif

