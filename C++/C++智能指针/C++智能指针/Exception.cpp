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
	NetException e(404, "找不到网页");
	throw e;
}

void TestFunc2()
{
	DbException e(504, "数据库未打开");
	throw e;
}
int main()
{
	try
	{
		TestFunc1();
		TestFunc2();
	}
	catch (const Exception& e) //自己代码中的异常
	{
		e.What();
	}
	catch (const exception& e) //标准库中的异常
	{
		e.what();
	}
	catch (...) //其他异常
	{
		cout << "未知异常" << endl;
	}
	return 0;
}
#endif