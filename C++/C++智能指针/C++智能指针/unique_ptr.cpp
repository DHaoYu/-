#define _CRT_SECURE_NO_WARNNINGS

#include<iostream>
#include<memory>
using namespace std;

#if 0
int main()
{
	default_delete<int> d; //设置默认的删除对象类型为d
	unique_ptr<int> u1;
	unique_ptr<int> u2(nullptr);
	unique_ptr<int> u3(new int(3));
	unique_ptr<int> u4(new int(4), d);
	cout << *u3 << endl;
}
#endif