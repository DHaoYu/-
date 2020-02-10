#define _CRT_SECURE_NO_WARNNINGS 1

#include<iostream>
using namespace std;

#if 0
//单例模式
//懒汉模式 --->用的时候才会去创建
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (flag == nullptr)
		{
			flag = new Singleton();
		}
		return flag;
	}
	~Singleton()
	{
		if (flag != nullptr)
			flag = nullptr;
	}
private:
	Singleton()
	{}
	static Singleton *flag;
};

Singleton* Singleton::flag = nullptr;

int main()
{
	Singleton* p1 = Singleton::GetInstance();
	Singleton *p2 = Singleton::GetInstance();//p1与p2指向相同对象
}
#endif

#if 0
class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (ptr == nullptr)
			ptr = new Singleton();
		return ptr;
	}
	Singleton(const Singleton&) = delete;
	Singleton operator=(Singleton&) = delete;
private:
	Singleton()
	{}
	static Singleton* ptr;
};
#endif
#include<set>

#if 0
int main()
{
	int myints[] = { 60, 50, 30, 10, 20 };
	multiset<int, less<int>> ms(myints, myints + 5);
	for (auto e : ms)
		cout << e << " ";
}
#endif

#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
//前K个最多出现的单词
class Solution {
private:
	static bool campare(pair<string, int> p1, pair<string, int> p2){
		if (p1.second < p2.second)
			return false;
		if (p1.second > p2.second)
			return true;

		return p1.first < p2.first;
	}
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> res;
		if (words.size() == 0)
			return res;

		vector<pair<string, int>> W;
		unordered_map<string, int> freq;
		for (int i = 0; i < words.size(); ++i)
			++freq[words[i]];

		unordered_map<string, int>::iterator it = freq.begin();
		while (it != freq.end())
		{
			pair<string, int> p(it->first, it->second);
			W.push_back(p);
			++it;
		}
		sort(W.begin(), W.end(), campare);
		for (int i = 0; i<k; i++)
			res.push_back(W[i].first);

		return res;
	}
};
