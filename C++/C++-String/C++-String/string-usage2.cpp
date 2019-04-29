#include<iostream>
#include<string>

using namespace std;

#if 0
int main()
{
	string s = "string-usage.cpp";
	size_t pos = s.rfind('.');
	size_t n = s.size() - pos;

	cout << s.substr(pos + 1, n) << endl;
	return 0;
}
#endif

#if 0
int main()
{
	string s = "https://github.com/DHaoYu/C-Cplusplus/tree/master/C%2B%2B";
	size_t start = s.find("://");
	size_t finish = s.find('/', start + 3);

	cout << s.substr(start + 3, finish - start - 3) << endl;
	return 0;
}
#endif

#if 0
void TestPushback(string& s)
{
	size_t sz = s.capacity();
	for (int i = 0; i < 100; i++)
	{
		s += '#';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "s.capacity()changed!--->"<< i << endl;
		}
	}
}


void TestReserve(string& s)
{
	s.reserve(100);
	size_t sz = s.capacity();

	for (int i = 0; i < 100; i++)
	{
		s += '#';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "s.capacity()changed!--->" << i << endl;
		}
	}
}


int main()
{
	string s1, s2;
	TestPushback(s1);
	TestReserve(s2);
	return 0;
}
#endif

#if 0
#include<algorithm>

//·­×ª×Ö·û´®
void TestReverse(string& s)
{
	if (s.empty())
		return;

	reverse(s.begin(),s.end());
	cout << s << endl;
}

#if 0
void TestReverseString(string& s)
{
	if (s.size() == 0)
		return;

		//	cout <<  << endl;
		//s.end()--;
	TestReverseString(s);
}
#endif

void TestReverseString(string& s)
{
	if (s.empty())
		return;

	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin <= end)
	{
		swap(s[begin], s[end]);
		++begin;
		--end;
	}

	cout << s << endl;
}

int main()
{
	string s = "hello bit!";
	TestReverse(s);
	TestReverseString(s);
	return 0;
}
#endif

