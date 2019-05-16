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

	for (auto e : l5)//·¶Î§for
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
	list<int> l3 = l2;//¸³ÖµÔËËã·ûÖØÔØ

	for (auto e : l3)//·¶Î§for
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
