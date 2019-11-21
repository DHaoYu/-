#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
using namespace std;

#if 0
struct str_t{
	long long len;
	char data[32];
};
int main()
{
	cout << sizeof(str_t) << endl;
	return 0;
}

#endif
#if 0
class B{
public:
	B()
	{
		cout << "default constructor" << " ";
	}
	~B(){
			cout << "destructed" << "";
	}
	B(int i) : data(i){
		cout<< "constructed by parameter"<< data << " ";
}
private: int data;
};

B Play(B b)
{
	return b;
}
int main(int argc, char *argv[])
{
	B temp = Play(5);
	return 0;
}
#endif
#if 0
#include < iostream>
using namespace std;
class A{
public:
	virtual void print()
	{
		cout << "A::print()" << "\n";
	}
};
class B : public A{
public: 
	virtual void print()
	{
		cout << "B::print()" << "\n";
	}
};
class C : public A{
public: 
	virtual void print()
	{
		cout << "C::print()" << "\n";
	}
};
void print(A a)
{
	a.print();
}
int main()
{
	A a, *aa, *ab, *ac;
	B b;
	C c;
	aa = &a;
	ab = &b;
	ac = &c;
	a.print();
	b.print();
	c.print();
	aa->print();
	ab->print();
	ac->print();
	print(a);
	print(b);
	print(c);
}
#endif

#if 0 
//参数解析
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int pos = 0;
	string s;
	vector<string> vs;
	while (cin >> s)
		vs.push_back(s);
	for (int i = 0; i < vs.size(); i++)
	{
		if (vs[i][0] == '\"')
		{
			do
			{
				vs[i] += vs[i + 1];
				i += 1;
			} while (*(vs[i].end() - 1) != '\"');
			vs[i].erase(vs[i].begin());
			vs[i].erase(vs[i].end() - 1);
		}
	}
	cout << vs.size() << endl;
	for (auto e : vs)
		cout << e << endl;
}
#endif

#if 0
//跳石板
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INT_MAX 100001
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> dp(m + 1, INT_MAX);  //dp[i]为在第i个石板时，所需要的步数，初始设为条件范围内的最大值
		dp[n] = 0;
		for (int i = n; i <= m; i++)
		{
			for (int j = 2; j*j <= i; j++)   //比如i为8，当找到i的一个约数j为2时，另一个约数就为i/j
			{                             //所以只需要找j*j<=i,事实上如果不这样做，部分用例运行超时
				if (i%j == 0)
				{
					if (i + j <= m)
						dp[i + j] = min(dp[i + j], dp[i] + 1);
					if (i + i / j <= m) //关键步骤
						dp[i + i / j] = min(dp[i + i / j], dp[i] + 1);
				}
			}
		}
		if (dp[m] == INT_MAX)
			cout << "-1" << endl;
		else
			cout << dp[m] << endl;
	}
}
#endif

#if 0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> dp(m + 1, 0);
		dp[n] = 1;
		for (int i = n; i <= m; i++)
		{
			if (dp[i] == 0)
				continue;
			for (int j = 2; j <= sqrt(i); j++)
			{
				if (i % j == 0) //说明j和（i/j）都是i约数
				{
					if (i + j <= m) //处理j
					if (dp[j + i] == 0)
						//如果是dp[i+(i/j)]==0，则，先进行dp[i]+1操作,之后再进行min
						dp[i + j] = dp[i] + 1;
					else
						dp[i + j] = min(dp[i + j], dp[i] + 1);
					if (i + (i / j) <= m)//处理（i/j）
					if (dp[i + (i / j)] == 0)
						dp[i + (i / j)] = dp[i] + 1;
					else
						dp[i + (i / j)] = min(dp[i] + 1, dp[i + (i / j)]);
				}
			}
		}
		cout << dp[m]  - 1 << endl;
	}
}
#endif