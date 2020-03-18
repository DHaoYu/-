

#include<map>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#if 0
//int main()
//{
//	map<int, int> m{ { 1, 2 }, { 2, 4 }, { 3, 4 }, { 4, 8 } };
//	for (auto e : m)
//	{
//		if (e.first % 2 == 0)
//			m.erase(e.first);
//	}
//
//}

string getSentence(vector<string>& strs) {
	// write code here
	for (int i = 0; i < strs[0].size() - 2; ++i)
	{
		if (strs[0][i] == '{' && strs[0][i + 2] == '}')
		{
			int k = (int)strs[0][i + 1] - 48;
			strs[0].erase(i, 3);
			if (k + 1 > strs.size() - 1)
				strs[0].insert(i, "null");
			else
				strs[0].insert(i, strs[k + 1]);
		}
	}
	return strs[0];
}

struct Point {
	int x;
	int y;
};

int getClosestDistance(vector<Point>& points) {
	// write code here
	int num = 99999999;
	for (int i = 0; i < points.size(); ++i)
	{
		for (int j = i + 1; j < points.size(); ++j)
		{
			int x1 = (points[i].x - points[j].x);
			int y1 = (points[i].y - points[j].y);
			int temp = (int)sqrt(x1*x1 + y1*y1);
			if (temp < num)
				num = temp;
		}
	}
	return num;
}
#include<stack>

int longestValidSquareBracket(string s) {
	// write code here
	stack<char> st;
	for (size_t i = 0; i < s.size(); ++i)
	{
		st.push(s[i]);
	}
	int max = 0;
	while (!st.empty())
	{
		if (st.top() == '[')
			st.pop();
		int temp = 0;
		while (!st.empty() && st.top() == ']')
		{
			st.pop();
			if (!st.empty() && st.top() == '[')
			{
				temp += 2;
				st.pop();
			}
			if (temp >= max)
				max = temp;
		}
	}
	return max;
}

int main()
{
	//vector<string> str{ "I {0} you !", "miss" };
	//vector<string> str{ "study {0}, {6} Make {1} every {2}, {5}", "hard", "progress", "day"};
	//getSentence(str);
	//cout << -13 * -13 << endl;
	//vector<Point> v{ { 63, 60 }, { 42, 46 }, { 58, 72 } };
	//getClosestDistance(v);

	string str = "][][]]";
	longestValidSquareBracket(str);
}
#endif

#if 0
class Base
{
public:
	Base()
		:a(10)
	{
		cout << "Base" << endl;
	}
	int a;
	virtual void func(){};
	static void fun(){};
};

int main()
{
	cout << sizeof(Base) << endl;
	Base b;
	cout << sizeof(b) << endl;

}
#endif

#if 0
typedef void(*FUNC)();
//C语言模拟实现继承和多态
struct CA
{
	FUNC f;
	int _a;
};
struct CB
{
	CA _ca;//C语言模拟C++的公有继承
	int _b;
};
//A对象的成员函数
void FunCA()
{
	cout << "CA" << endl;
}
//B对象的成员函数
void FunCB()
{
	cout << "CB" << endl;
}

//调用C语言
void func(CA*ptr)
{
	ptr->f();
}

int main()
{
	//测试C模拟实现继承和多态
	CA ca;
	CB cb;
	ca.f = FunCA;//赋值
	cb._ca.f = FunCB;//赋值

	func(&ca);
	func((CA*)&cb);//强制类型装换
	system("pause");
	return 0;
}
#endif

int main()
{
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << i << " ";
	//}


	map<int, int> m{ { 1, 2 }, { 2, 4 }, { 3, 5 }, { 4, 8 } };
	auto it = m.begin();
	for (; it != m.end();)
	{
		if (it->first % 2 == 0)
			m.erase(it++);
		else
			it++;
	}

}