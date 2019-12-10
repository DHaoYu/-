#define _CRT_SECURE_NO_WARNNINGS 1

#if 0
//最难的问题

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] <= 'E' && s[i] >= 'A')
				s[i] += 21;
			else if (s[i] >= 'F' && s[i] <= 'Z')
				s[i] -= 5;
			else
				continue;
		}
		cout << s << endl;
	}
	return 0;
}
#endif


#if 0
//因子个数
// write your code here cpp
#include<iostream>
#include<set>
using namespace std;

int main()
{
	int num = 0;
	while (cin >> num)
	{
		set<int> st;
		int i = 2;
		while (num>1)
		{
			if (num % i == 0)
			{
				st.insert(i);
				num /= i;
			}
			else
				i++;
		}
		cout << st.size() << endl;
	}
	return 0;
}
#endif
