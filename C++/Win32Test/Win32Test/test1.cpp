#define _CRT_SECURE_NO_WARNNINGS 1

#include "UIlib.h"
using namespace DuiLib;

#pragma comment(lib, "DuiLib_ud.lib") //附加静态库

class CDuiFramWnd : public WindowImplBase
{
protected:
	virtual CDuiString GetSkinFolder()
	{
		return _T("");
	}

	virtual CDuiString GetSkinFile()
	{
		return _T("MakeGiff\\test.xml");
	}

	virtual LPCTSTR GetWindowClassName(void)const
	{
		return _T("DuiWnd");
	}

	virtual void Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))
		{
			MessageBox(m_hWnd, _T("按钮单击"), _T("test"), IDOK);
		}
	}
};


int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int
	nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);// 设置资源的默认路径（此处设置为和exe在同一目录）
	
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	CDuiFramWnd framWnd;
	// Cashier即在窗口右上角显式的名字
	// UI_WNDSTYLE_FRAME: duilib封装的宏，代表窗口可视，具有标题栏，最大化最小化，关闭功能等
	// WS_EX_WINDOWEDGE: Win32的窗口风格，带有边框
	framWnd.Create(NULL, _T("DuilibTest"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);

	framWnd.CenterWindow();

	//显示窗口，激活消息循环
	framWnd.ShowModal();
	return 0;
}



