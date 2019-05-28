#include<iostream>
#include<time.h>
#include <sys/timeb.h>
using namespace std;

#if 0
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a, b;
	clock_t start, finish;
	cin >> a >> b;
	if (a>b)
		swap(a, b);
	start = clock();
	for (int i = a; i>0; i--)
	{
		if (a%i == 0 && b%i == 0)
			a /= i;
	}
	finish = clock();
	cout << a*b << endl;
	cout << finish - start << endl;
	return 0;
}

//int main()
//{
//	int a,b;
//	int i=0;
//    cin>>a>>b;
//    	clock_t start,finish;
//    	start = clock();
//    for(i=1;;i++)
//    {
//    	if(i%a==0 && i%b==0)
//    	{
//    		cout<<i<<endl;
//    		break;
//		}
//
//	}
//	finish = clock();
//	cout<<finish-start<<endl;
//	return 0;
//}
#endif

//有错误----逻辑方面有点难，不太会写
#include<iostream>
#include<string>
#include<vector>
using namespace std;


void lengthAphSort(vector<string>& v, int n)
{
	int length = 0;
	int aph = 0;
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int j = 0;
		while (v[i][j] <= v[i + 1][j])
		{
			if (v[i][j] == v[i + 1][j])
				j++;
			else
				break;
			if (j == v[i].size() || j == v[i + 1].size())
				break;
		}
		if (j != v[i].size() && j != v[i + 1].size())
			break;
	}
	if (i + 1 == n)
		aph = 1;
	i = 0;
	while (i < n - 1)
	{
		if (v[i].size() <= v[i + 1].size())
			i++;
		else
			break;
	}
	if (i + 1 == n)
		length = 1;

	if (length == 1 && aph == 1)
	{
		cout << "both" << endl;
		return;
	}
	if (length == 0 && aph == 1)
	{
		cout << "lexicographically" << endl;
		return;
	}
	if (length == 1 && aph == 0)
	{
		cout << "lengths" << endl;
		return;
	}
	if (length == 0 && aph == 0)
	{
		cout << "none" << endl;
	}
	return;
}

int main()
{
	int n = 0;
	cin >> n;
	int i = 0;
	vector<string> v(n);
	fflush(stdin);
	while (i < n)
	{
		getline(cin, v[i]);
		i++;
	}

	lengthAphSort(v, n);

	return 0;
}
