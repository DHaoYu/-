#define _CRT_SECURE_NO_WARNNINGS 1

#include "UIlib.h"
using namespace DuiLib;

#pragma comment(lib, "DuiLib_ud.lib")

class CDuiFramWnd : public CWindowWnd
{
public:
	// CWindowWnd��Ĵ��麯�����ڸú����б��뷵���û������崰�ڵ������ƣ�ע�ᴰ��ʱ��Ҫ�õ�
	virtual LPCTSTR GetWindowClassName() const
	{
		return _T("DuiFramWnd");
	}
	//virtual LRESULT HandleMessage()
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;
		if (uMsg == WM_CREATE)
		{
			CControlUI *pWnd = new CButtonUI;
			pWnd->SetText(_T("Hello World"));
			pWnd->SetBkColor(0xFF00FF00);
			// ��ʼ��m_PaintManager����Ĵ��ھ����������Ϣʱ��Ҫ�õ�
			m_PaintManager.Init(m_hWnd);
			// ����ť���������ƹ�������
			m_PaintManager.AttachDialog(pWnd);
			return lRes;
		}
		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}
		// ע�⣺__superΪvs��չ��һ���ؼ��֣���˼�ǵ��û���ĳ�Ա
		return __super::HandleMessage(uMsg, wParam, lParam);
	}
};
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	CDuiFramWnd framWnd;
	// Cashier���ڴ������Ͻ���ʽ������
	// UI_WNDSTYLE_FRAME: duilib��װ�ĺ꣬�����ڿ��ӣ����б������������С�����رչ��ܵ�
	// WS_EX_WINDOWEDGE: Win32�Ĵ��ڷ�񣬴��б߿�
	framWnd.Create(NULL, _T("Ҧ���"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	//��ʾ���ڣ�������Ϣѭ��
	framWnd.ShowModal();
	return 0;
}
