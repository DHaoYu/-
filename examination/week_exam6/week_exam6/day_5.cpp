#define _CRT_SECURE_NO_WARNNINGS 1
#if 0
#include<iostream>
using namespace std;

long long Literal(int n)
{
	if (n == 2)
		return 1;
	if (n == 1 || n == 0)
		return 0;
	return (n - 1)*(Literal(n - 1) + Literal(n - 2));
}

int main()
{
	int n;
	while(cin>>n)
	{
		double long count = Literal(n);
		double long sum = 1;
		while (n)
		{
			sum *= n;
			n--;
		}
		double long x = count / sum;
		printf("%.2lf%%\n", x*100);
	}
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace std;

void CcList(string& list)
{
	string se;
	getline(cin, se);
	string str;
	size_t pos = 0;
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list.find('"')==string::npos)
			if (list.find(se)!=string::npos)
			{
				cout << "Ignore" << endl;
				return;
			}
			else
			{
				cout << "Important!" << endl;
				return;
			}
		else
		{
			size_t npos = list.find('"',pos);
			str = list.substr(pos, npos);
			pos = npos;
			if (string::npos!=str.find(se) && str.size() == se.size())
			{
				cout << "Igonre" << endl;
				return;
			}
		}
	}
	cout << "Important!" << endl;

}

int main()
{
	string list;
	string se;
	while (getline(cin, list))
	{
		CcList(list);
	}
	return 0;
}
#endif
