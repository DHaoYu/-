#define _CRT_SECURE_NO_WARNNINGS


#include<iostream>
#include<memory>
using namespace std;

#if 0
int main()
{
	default_delete<int> d; //����Ĭ�ϵ�ɾ����������Ϊd
	unique_ptr<int> u1;
	unique_ptr<int> u2(nullptr);
	unique_ptr<int> u3(new int(3));
	unique_ptr<int> u4(new int(4), d);
	cout << *u3 << endl;
}
#endif


#if 0
void Test1() throw(int)//�ú���ֻ���׳����ε��쳣
{
	throw 1.0;
}

void Test2() throw() //throw��ʲô��û�У���ʾ��ǰ����һ�������׳��쳣
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