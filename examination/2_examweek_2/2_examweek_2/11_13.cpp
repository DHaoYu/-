#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;

//int main()
//{
	//int p[][4] = { { 1 }, { 3, 2 }, {4, 5, 6}, {0} };//在数组未存放数据时，会补零
	//cout << p[1][2] << endl;
	//int n = 0;
	//char ch;
	//while (ch = getchar() != '\n')
	//	n++;
	//cout << n << endl;
	//for (i = 0; i < n; i++)
	//for (ch = getchar(); ch != '\n'; n++)
	//	cout << "11" << endl;
	//cout << n;
	//int a = 0, b = 1, temp = 0, num = 0;
	//int i = 2;
	//while (--i)
	//{
	//	temp = a;
	//	a = b;
	//	b = temp + a;
	//	num = a + b;
	//}
	//cout << num << endl;
//}

#if 0
//Fibonacci数列 ：输入一个x，输出距离x最近的fib数与x差的绝对值
#include<iostream>
using namespace std;

int main()
{
	int x;
	while (cin >> x)
	{
		int i = 0, temp = 0;
		int a = 0, b = 1, num = 0;
		while (1)
		{
			temp = a;
			a = b;
			b = temp + a;
			num = a + b;
			if ((num - x) >= 0 && (x - b) >= 0)
			{
				cout << ((num - x) > (x - b) ? (x - b) : (num - x)) << endl;
				break;
			}
		}
	}
}
#endif
#if 0
//合法括号序列判断
#include<algorithm>
#include<stack>

bool chkParenthesis(string A, int n) {
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (A[i] == '(')
			count++;
		else if (A[i] == ')')
			count--;
		else
			return false;
		if (count<0)
			return false;
	}
	return count == 0;
}
bool Judge(string A, int n)
{
        stack<char> s;
        for(int i = 0; i < n; i++)
        {
            if(A[i] == '(')
                s.push(A[i]);
            else if(A[i] == ')' && !s.empty())
                s.pop();
            else
                return false;
        }
        return s.empty();
    }
}

int main()
{
	cout << chkParenthesis("()()(((())))", 12);
	cout << chkParenthesis(")()(", 4);
}
#endif