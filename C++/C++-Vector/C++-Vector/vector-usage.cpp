#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

#if 0
int main()
{
	vector<int> v1{ 1, 2, 3, 4 };//C++11
	vector<int> v2;//����һ������v2
	vector<int> v3(1);//����1���ռ�
	vector<int> v4(4);//����4���ռ�
	vector<string> v5{ "123", "234" };
	vector<char> v6{ 'a', 'b', 'c', 'd' };
	vector<char> v7{ 65, 66, 67, 68 };
	return 0;
}
#endif

#if 0
int main()
{
	vector<int> v1;
	vector<int> v2(10, 5);
	
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };	
	vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));
	vector<int> v4(v3);
	v1 = v3;
	return 0;
}
#endif


#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	
	//cout << v << endl;//error û����֮ƥ��Ĳ�����
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	//auto it = v.begin();
	vector<int>::iterator it = v.begin();
	for (; it < v.end(); it++)
		cout << *it << " ";
	cout << endl;

	v.resize(20, 1);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	return 0;
}
#endif


#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << v.max_size() << endl;//����size���������
	v.reserve(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << v.max_size() << endl;

	v.reserve(100);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << v.max_size() << endl;
	cout << v.empty() << endl;

	//v.reserve(1073741824);//error ����max_size�޷���������
	//cout << v.size() << endl;
	//cout << v.capacity() << endl;
	//cout << v.max_size() << endl;
	return 0;
}
#endif

#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << v[0] << endl;
	cout << v[9] << endl;
	//cout << v[-1] << endl;//assert
	cout << v.at(6) << endl;
    //cout << v.at(10) << endl;//error 
	cout << v.front() << " " << v.back() << endl;
	return 0;
}
#endif

#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v1{ 1, 2, 3 };
	for (auto e : v1)
		cout << e << " ";
	cout << endl;

	vector<int> v2;
	auto it = v1.begin();
	v2.assign(it, v1.end());
	for (auto e : v2)
		cout << e << " ";
	cout << endl;

	v1.assign(5, 1);
	for (auto e : v1)
		cout << e << " ";
	cout << endl;

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> v3 = { 1, 2, 3 };
	v3.assign(array, array + sizeof(array) / sizeof(array[0]));
	for (auto e : v3)
		cout << e << " ";
	cout << endl;

	return 0;
}
#endif

#if 0
int main()
{
	//�����vector����size�Ĵ�С����ռ䣬�󣬰���1.5���ķ�����������
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 };
	v.push_back(1);
	cout << v.capacity() << endl;
	v.push_back(2);
	cout << v.capacity() << endl;
	v.push_back(3);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	cout << v.capacity() << endl;

	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.pop_back();
	v.pop_back();
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	return 0;
}
#endif

#if 0
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 };
	//v.insert(4, 10);//insert �� pos��λ���ǰ��յ������������ͽ��д��ε�
	v.insert(v.begin() + 3, 10);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.insert(v.end(), 5, 0);
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	int array[] = { 1, 2, 3 };
	//����Խ�磡
	v.insert(v.end(), array, array + sizeof(array) / sizeof(array[0]));
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	auto it = v.begin();//begin ��1��ʼ������
	v.erase(it + 3);
	//v.erase(it);��itλ��ɾ���ˣ��ᵼ�µ�����ʧЧ����Ҫ���¸��µ�����
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.erase(it + 10, v.end());//������ʧЧ
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.erase(v.end(), it + 4);
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	return 0;
}
#endif

#if 0
int main()
{
	vector<int> v1{ 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> v2{ 1, 2, 3 };
	v1.swap(v2);
	for (auto e : v1)
		cout << e << " ";
	cout << endl;

	for (auto e : v2)
		cout << e << " ";
	cout << endl;

	v1.clear();
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;

	v2.clear();//û�����capacity�����ݣ���˼�ǻ����Խ��ŷ�ֵ
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
	
	return 0;
}
#endif

#if 0
int main()
{
	vector<int> v1{ 3, 2, 1, 7, 5, 4, 6, 8 };
	sort(v1.begin(), v1.end());//�����㷨
	for (auto e : v1)
		cout << e << " ";
	cout << endl;

	return 0;
}
#endif

#if 0
int main()
{
	vector<int> v1{ 3, 2, 1, 7, 5, 4, 6, 8 };
	v1.reserve(100);
	cout << v1.size() << " " << v1.capacity() << endl;
	for (auto e : v1)
		cout << e << " ";
	cout << endl;
	return 0;
}
#endif

#if 0
int main()
{
	int a = int();
	cout << a << endl;
	int b(a);
	cout << b << endl;

	return 0;
}
#endif
#include<algorithm>

#if 1
int main()
{
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 };
	size_t pos = find(v.begin(), v.end(), 8) - v.begin();
	cout << pos << endl;
	return 0;
}
#endif