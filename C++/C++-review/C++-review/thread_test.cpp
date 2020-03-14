#include<thread>
#include<windows.h>
#include<iostream>

using namespace std;

#if 0
int number = 1;	//定义全局变量
CRITICAL_SECTION Critical;		//定义临界区句柄

unsigned long __stdcall ThreadProc1(void* lp) {
	while (number < 100) {
		EnterCriticalSection(&Critical);
		cout << "thread 1 :" << number << endl;
		++number;
		Sleep(100);
		LeaveCriticalSection(&Critical);
	}

	return 0;
}

unsigned long __stdcall ThreadProc2(void* lp) {
	while (number < 100) {
		EnterCriticalSection(&Critical);
		cout << "thread 2 :" << number << endl;
		++number;
		Sleep(100);
		LeaveCriticalSection(&Critical);
	}

	return 0;
}

int main() {
	InitializeCriticalSection(&Critical);	//初始化临界区对象
	CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);
	CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);

	Sleep(10 * 1000);
	system("pause");
	return 0;
}
#endif

#if 0
int number = 1;	//定义全局变量
HANDLE hEvent;	//定义事件句柄

unsigned long __stdcall ThreadProc1(void* lp) {
	while (number < 100) {
		WaitForSingleObject(hEvent, INFINITE);	//等待对象为有信号状态
		cout << "thread 1 :" << number << endl;
		++number;
		Sleep(100);
		SetEvent(hEvent);
	}

	return 0;
}

unsigned long __stdcall ThreadProc2(void* lp) {
	while (number < 100) {
		WaitForSingleObject(hEvent, INFINITE);	//等待对象为有信号状态
		cout << "thread 2 :" << number << endl;
		++number;
		Sleep(100);
		SetEvent(hEvent);
	}

	return 0;
}

int main() {
	hEvent = CreateEvent(NULL, FALSE, TRUE, (LPCWSTR)"event");
	CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);
	CreateThread(NULL, 0, ThreadProc2, NULL, 0, NULL);

	Sleep(10 * 1000);
	system("pause");
	return 0;
}
#endif

#include<vector>

void LIS(vector<int>& v)
{
	//动态规划
	vector<int> dp(v.size(), 1);
	int sum = 1;
	for (size_t i = 1; i<v.size(); i++)
	{
		for (size_t j = 0; j<i; j++)
		if (v[i]>v[j])
			dp[i] = max(dp[i], dp[j] + 1);
		sum = max(sum, dp[i]);
	}
	cout << sum << endl;
}


int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		vector<int> v(n);
		for (size_t i = 0; i<n; i++)
			cin >> v[i];
		LIS(v);
	}
	return 0;
}
