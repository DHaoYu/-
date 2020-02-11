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


#if 0
void Test1() throw(int)//该函数只能抛出整形的异常
{
	throw 1.0;
}

void Test2() throw() //throw中什么都没有，表示当前函数一定不会抛出异常
{
	throw 1.0;
}
#endif

#if 0
int main()
{
	char* p = nullptr;
	try
	{
		p = new char[0x7fffffff];
	}
	catch (const std::bad_alloc& e)
	{
		e.what();
		return 0;
	}
	delete[] p;
	return 0;
}
#endif