
// OurLogicSimulator.h : OurLogicSimulator ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// COurLogicSimulatorApp:
// �� Ŭ������ ������ ���ؼ��� OurLogicSimulator.cpp�� �����Ͻʽÿ�.
//

class COurLogicSimulatorApp : public CWinApp
{
public:
	COurLogicSimulatorApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COurLogicSimulatorApp theApp;
