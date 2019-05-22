#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0
int main()
{
	char acX[] = "abc";
	char acY[] = { 'a', 'b', 'c' };
	char *szX = "abc";
	char *szY = "abc";
	acX[2] = 'd';
	acY[0] = 'd';
	//*(szX + 1) = 'd';
	//szX[1] = 'd';
	cout << sizeof(acX) << " " << sizeof(acY) << endl;
	cout << sizeof(unsigned) << endl;
	return 0;
}
#endif

#if 0
#include<vector>

int Sort_list(vector<int>& arr, int n)
{
	int count = 1;
	int i = 0;
	for (i = 1; i<n - 1; i++)
	{
		//if (arr[i - 1]>arr[i] && arr[i]<arr[i + 1])//Ñ°ÕÒ¹È
		//	count++;
		//if (arr[i - 1]<arr[i] && arr[i]>arr[i + 1])//Ñ°ÕÒ·å
		//	count++;
		if ((arr[i - 1]>arr[i] && arr[i]<arr[i + 1]) ||
			(arr[i - 1]<arr[i] && arr[i]>arr[i + 1]))
		{
			count++;
			if (i != n - 3)
				i++;
		}
	}
	return count;
}

int main()
{
	int n;
	vector<int> array;
	cin >> n;
	array.resize(n);
	for (int i = 0; i<n; i++)
	{
		cin >> array[i];
	}
	cout << Sort_list(array, n) << endl;
	return 0;
}
#endif

#include<string>

string Word_inverse(string& s)
{
	int i = 0;
	int j = s.size() - 1;
	string sTemp;
	for (i = s.size() - 1; i > 0; i--)
	{
		if (s[i] == 32)
		{
			sTemp.append(s.begin() + i + 1, s.begin() +j + 1 );
			sTemp.push_back(' ');
			j = i - 1;
		}
	}
	if (i == 0)
		sTemp.append(s.begin() + i, s.begin() + j + 1);
	return sTemp;
}

int main()
{
	string s,Sout;
	getline(cin, s);
	
	Sout = Word_inverse(s);
	cout << Sout << endl;
	return 0;
}