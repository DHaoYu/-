#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
#include<vector>

using namespace std;
#if 0
int Sul(int m , int n)
{
	vector<vector<int>> mapNum(m, vector<int>(n, 1));
	vector<vector<int>> src(m, vector<int>(n, 1));
	for (int i = 1; i < m; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if (src[i][j] == 0)
				mapNum[i][j] = mapNum[i - 1][j] + mapNum[i][j - 1];
			else
				mapNum[i][j] == 0;
		}
	}
	return mapNum[m - 1][n - 1];
}

int main()
{
	cout << Sul(2, 3) << endl;
	return 0;
}
#endif


#if 0
size_t strlcpy(char *dst, const char *src, size_t siz)
{
	register char *d = dst;
	register const char *s = src;
	register size_t n = siz;
	if (n != 0 && --n != 0) {
		do {
			if ((*++d = *++s) == 0)
				break;
		} while (--n != 0);
	}
	if (n == 0) {
		if (siz == 0)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src);
}

int main()
{
	char s1[] = "abcderf";
	char s2[] = "";

	cout<<strlcpy(s2, s1, 7);
}
#endif


#if 0
struct A
{
	char a;
	int b;
	double c;
	int a1;
	char a2;
};

struct B
{
	char a;
	char c;
	double b;
	int _a;
};

int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
}
#endif

#if 0
int main()
{
	int x;
	int a = 10;
	while(cin >> x)
	{
		switch (x)
		{
		case 1:
			if (a > 1 && a <= 10)
			{
				cout << "a == " << a << endl;
			}
			break;
		case 2:
			cout <<"x is "<< x << endl;
			break;
		default:
			cout << "defaut" << endl;
		}
	}
}
#endif