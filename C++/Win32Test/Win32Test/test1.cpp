#define _CRT_SECURE_NO_WARNNINGS 1

#include "UIlib.h"
using namespace DuiLib;

#pragma comment(lib, "DuiLib_ud.lib")

class CDuiFramWnd : public CWindowWnd
{
public:
	// CWindowWnd类的纯虚函数，在该函数中必须返回用户所定义窗口的类名称，注册窗口时需要用到
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
			// 初始化m_PaintManager对象的窗口句柄，发送消息时需要用到
			m_PaintManager.Init(m_hWnd);
			// 将按钮关联到绘制管理器上
			m_PaintManager.AttachDialog(pWnd);
			return lRes;
		}
		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}
		// 注意：__super为vs扩展的一个关键字，意思是调用基类的成员
		return __super::HandleMessage(uMsg, wParam, lParam);
	}
};
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	CDuiFramWnd framWnd;
	// Cashier即在窗口右上角显式的名字
	// UI_WNDSTYLE_FRAME: duilib封装的宏，代表窗口可视，具有标题栏，最大化最小化，关闭功能等
	// WS_EX_WINDOWEDGE: Win32的窗口风格，带有边框
	framWnd.Create(NULL, _T("姚嘉璐"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	//显示窗口，激活消息循环
	framWnd.ShowModal();
	return 0;
}
