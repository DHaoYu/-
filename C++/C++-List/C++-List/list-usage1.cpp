#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>

using namespace std;

#if 0
int main()
{
	list<int> l1;
	list<int> l2(4, 1);
	list<int> l3(l2.begin(), l2.end());
	list<int> l4(l3);
	//list<int> l5(l3.begin(), l3.end());

	int array[] = { 1, 2, 3, 4, 5, 6, 7,};
	list<int> l5(array, array + sizeof(array) / sizeof(array[0]));	
	list<int>::iterator it;
	for (it = l5.begin(); it != l5.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (auto e : l5)//��Χfor
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
#endif

#if 0
int main()
{
	list<int> l1;
	list<int> l2(4, 1);
	list<int> l3 = l2;//��ֵ���������

	for (auto e : l3)//��Χfor
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
#endif

#if 0
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));
	
	list<int>::reverse_iterator rit;
	for (rit = L.rbegin(); rit != L.rend(); rit++)
	{
		cout << *rit << " ";
	}
	cout << endl;

	return 0;
}
#endif

#if 0
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));

	cout << L.size() << endl;
	cout << L.empty() << endl;
	cout << L.front()<< endl;
	cout << L.back() << endl;

	L.resize(5);
	cout << L.size() << endl;
	cout << L.empty() << endl;

	L.resize(0);
	cout << L.size() << endl;
	cout << L.empty() << endl;

	L.resize(100);
	cout << L.size() << endl;
	cout << L.empty() << endl;

	return 0;
}
#endif

#if 0
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, };
	list<int> L(array, array + sizeof(array) / sizeof(array[0]));
	list<int> l2;
	list<int> l3;
	l2.assign(L.rbegin(), L.rend());

	for (auto e : l2)
		cout << e << " ";
	cout << endl;

	return 0;
}
#endif


#if 0
int main()
{
	list<int> L{ 1, 3, 2, 7, 4, 3 };
	L.assign(4,10);//assign ��ֵ����ԭ�д��ڵ�ֵ���и��£�Ϊ10 10 10 10
	for (auto e : L)
		cout << e << " ";
	cout << endl;
	
	L.assign(L.begin(), L.end());
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	list<int> L2{ 1, 3, 2, 7, 4, 3 };
	L2.push_front(10);//ͷ��
	L2.push_front(11);
	//L2.push_front("abc");//error ���Ͳ�ƥ�� 
	L2.pop_front();//ͷɾ
	L2.push_back(100);//β��
	L2.push_back(101);
	L2.pop_back();//βɾ

	return 0;
}
#endif

#if 0
int main()
{
	list<int> l{ 1, 3, 2, 7, 4, 3 };
	list<int> l2{ 1, 2, 3, 4 };
	auto it = l.begin();
	it++;
	l.insert(l.begin(), 10);
	l.insert(it, 100);

	for (auto e : l)
		cout << e << " ";
	cout << endl;
	
	l.insert(l.end(), l2.begin(), l2.end());
	for (auto e : l)
		cout << e << " ";
	cout << endl;
	
	it = l.begin();
	advance(it, 5);//����ڵ�����ֻ�ܽ���++  --����������advance��������ֱ��
				   //�ƶ����λ��	
	cout << *it << endl;
	l.erase(it);//�κ�ʹ�������ƶ��ĳ�Ա���������п���ʹ������ʧЧ
	advance(it=l.begin(), 3);//ˢ�µ���������
	for (auto e : l)
		cout << e << " ";
	cout << endl;

	l.erase(it,l.end());
	for (auto e : l)
		cout << e << " ";
	cout << endl;
	return 0;
}
#endif

#if 0
#include<string>

int main()
{
	list<int> l{ 1, 3, 2, 7, 4, 3 };
	list<int> l2{ 1, 2, 3, 4 };
	list<string> l3{ "abc", "asd", "qewrt" };
	l.swap(l2);//����
	for (auto e : l)
		cout << e << " ";
	cout << endl;

	l.clear();//���
	for (auto e : l)
		cout << e << " ";
	cout << endl;
	//l2.swap(l3)//error ���Ͳ�ƥ��


	
	return 0;//��ʾ�û�д�ĳ������쳣�������˳�
}
#endif
