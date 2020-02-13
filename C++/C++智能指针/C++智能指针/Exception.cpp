#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
#include<string>
using namespace std;

#if 0
class Exception
{
public:
	Exception(size_t errNo, const string& errInfo)
		:_errNo(errNo)
		, _errInfo(errInfo)
	{}

	virtual void What() const = 0;
protected:
	size_t _errNo;
	string _errInfo;
};

class NetException : public Exception
{
public:
	NetException(size_t errNo, const string& errInfo)
		:Exception(errNo, errInfo)
	{}

	virtual void What()const
	{
		cout << _errNo << "--->" << _errInfo << endl;
	}
};

class DbException : public Exception
{
public:
	DbException(size_t errNo, const string& errInfo)
		:Exception(errNo, errInfo)
	{}

	virtual void What()const
	{
		cout << _errNo << "--->" << _errInfo << endl;
	}
};

void TestFunc1()
{
	NetException e(404, "�Ҳ�����ҳ");
	throw e;
}

void TestFunc2()
{
	DbException e(504, "���ݿ�δ��");
	throw e;
}
int main()
{
	try
	{
		TestFunc1();
		TestFunc2();
	}
	catch (const Exception& e) //�Լ������е��쳣
	{
		e.What();
	}
	catch (const exception& e) //��׼���е��쳣
	{
		e.what();
	}
	catch (...) //�����쳣
	{
		cout << "δ֪�쳣" << endl;
	}
	return 0;
}
#endif