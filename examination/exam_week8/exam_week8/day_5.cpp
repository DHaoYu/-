#define _CRT_SECURE_NO_WARNNINGS 1

#if 0
// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

void judgeFiveline(vector<vector<char>>& v)
{
	for (size_t i = 0; i<20; i++)
	{
		for (size_t j = 0; j<20; j++)
		{
			if (v[i][j] == '*')
			{
				for (size_t pos = 0; pos<5; pos++)
				if (v[i + pos][j - pos] != '*')
					break;
				cout << "Yes" << endl;
				return;
			}
			if (v[i][j] == '+')
			{
				for (size_t pos = 0; pos<5; pos++)
				if (v[i + pos][j - pos] != '+')
					break;
				cout << "Yes" << endl;
				return;
			}
			if (v[i][j] == '*')
			{
				for (size_t pos = 0; pos<5; pos++)
				if (v[i + pos][j] != '*')
					break;
				cout << "Yes" << endl;
				return;
			}
			if (v[i][j] == '+')
			{
				for (size_t pos = 0; pos<5; pos++)
				if (v[i + pos][j] != '+')
					break;
				cout << "Yes" << endl;
				return;
			}
			if (v[i][j] == '*')
			{
				for (size_t pos = 0; pos<5; pos++)
				if (v[i + pos][j + pos] != '*')
					break;
				cout << "Yes" << endl;
				return;
			}
			if (v[i][j] == '+')
			{
				for (size_t pos = 0; pos<5; pos++)
				if (v[i + pos][j + pos] != '+')
					break;
				cout << "Yes" << endl;
				return;
			}
			if (v[i][j] == '*')
			{
				for (size_t pos = 0; pos<5; pos++)
				if (v[i][j + pos] != '*')
					break;
				cout << "Yes" << endl;
				return;
			}
			if (v[i][j] == '+')
			{
				for (size_t pos = 0; pos<5; pos++)
				if (v[i][j + pos] != '+')
					break;
				cout << "Yes" << endl;
				return;
			}
		}
	}
	cout << "No" << endl;
	return;
}

int main()
{
	char c;
	while (cin >> c)
	{
		vector<vector<char>> v(20, vector<char>(20));
		for (size_t i = 0; i<19; i++)
			for (size_t j = 0; j<20; j++)
			{
				char ch;
				cin >> ch;
				v[i][j] = ch;
			}
		judgeFiveline(v);

	}
	return 0;
}
#endif

#if 0
// write your code here cpp
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		getchar();
		stack<int> st;
		for (size_t i = 0; i<n; i++)
		{
			int sum = 0;
			string ch;
			cin >> ch;
			if (ch[0] == '+' ||ch[0] ==  '-' || ch[0] == '*' ||ch[0] == '/')
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				if (ch[0] == '+')
					sum = left + right;
				if (ch[0] == '-')
					sum = left - right;
				if (ch[0] == '*')
					sum = left*right;
				if (ch[0] == '/')
				{
					if (right != 0)
						sum = left / right;
					else
						return 0;
				}
				st.push(sum);
			}
			else
			st.push(atoi(ch.c_str()));
		}
		cout << (int)st.top() << endl;
	}
	return 0;
}
#endif