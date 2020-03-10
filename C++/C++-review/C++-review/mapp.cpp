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