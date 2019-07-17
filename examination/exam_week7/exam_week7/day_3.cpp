#define _CRT_SECURE_NO_WARNNINGS 1


#if 0
// write your code here cpp
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


//乒乓球筐
void JudgeBall(string& s1, string& s2)
{
	int length1, length2;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	size_t i = 0;
	while (i<s2.size())
	{
		if (s1.find(s2[i]) == string::npos)
		{
			cout << "No" << endl;
			return;
		}
		length1 = (s1.rfind(s2[i]) - s1.find(s2[i]) + 1);
		length2 = (s2.rfind(s2[i]) - s2.find(s2[i]) + 1);
		if (length1<length2)
		{
			cout << "No" << endl;
			return;
		}
		i++;
	}
	cout << "Yes" << endl;
}

int main()
{
	string s1, s2;
	while (cin >> s1)
	{
		cin >> s2;
		JudgeBall(s1, s2);
	}
	return 0;
}
#endif

#if 0
//查找兄弟单词
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void searchBrotherWord(vector<string>& vstr, string& src, int k)
{
	vector<string> vs = vstr;//拷贝一份，进行字符串排序，可以使用compare进行比较
	string s = src;//拷贝src进行sort，可以使其于vs进行compare，并不改变vstr中的顺序
	vector<string> v;//存放兄弟字符串
	int count = 0;
	sort(s.begin(), s.end());
	for (size_t i = 0; i<vstr.size(); i++)
	{
		sort(vs[i].begin(), vs[i].end());
		if (vs[i] == s && src != vstr[i])//判读是否为兄弟单词
		{
			v.push_back(vstr[i]);//将为兄弟单词的尾插如v
			count++;//计数++
		}
	}
	cout << count << endl;
	if (count != 0)
		cout << v[k - 1] << endl;
	else
		cout << 0 << endl;
}


int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> vstr(n);
		cin >> vstr[0];
		for (size_t i = 1; i<vstr.size(); i++)
		{
			cin >> vstr[i];
			if (vstr[i].compare(vstr[i - 1])<0)//字典中字符排序
				vstr[i].swap(vstr[i - 1]);
		}
		string src;
		cin >> src;
		int k;
		cin >> k;
		searchBrotherWord(vstr, src, k);
	}
	return 0;
}
#endif
