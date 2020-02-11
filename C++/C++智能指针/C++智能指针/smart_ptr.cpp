#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;

#if 0
template<class T>
class Smartptr
{
public:
	Smartptr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	//��Ҫ��ʽ��д���������캯��������ǳ�������ֵ�����
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~Smartptr()
	{
		if (_ptr)
			delete _ptr;
	}
protected:
	T* _ptr;
};

struct A
{
	int _a;
	char _b;
};
// RAII+ָ�����Ϊ�������ã�->��
void TestFunc()
{
	int *p = new int;
	*p = 10;
	Smartptr<int> sp(new int);
	*sp = 10;
	Smartptr<A> sp2(new A);
	sp2->_a = 10;
	//��ȷ���÷�ʽ
	//sp2->->_a = 10; C++�������Ż���ʡȥ�˵ڶ�����ͷ
	
}

int main()
{
	TestFunc();
	return 0;
}
#endif

#if 0
namespace Smart_ptr
{
	//���ǳ�������⣺������У�
	//auto_ptr �ڿ�������ʱ������Դת��,��������ָ��ָ��ͬһ����Դ
	//���Բ������Ұָ�������
template<class T>
class auto_ptr
{
public:
	auto_ptr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	auto_ptr(auto_ptr<T>& ap)
	{
		_ptr = ap._ptr;
		ap._ptr = nullptr;
	}

	T& operator*()const
	{
		return *_ptr;
	}

	auto_ptr<T>& operator=(auto_ptr<T>& ap)
	{
		if (this == &ap)
			return;
		if (_ptr)
			delete _ptr;
		_ptr = ap._ptr;
		ap._ptr = nullptr;
	}

	T* operator->()const
	{
		return _ptr;
	}

	~auto_ptr()
	{
		if (_ptr)
			delete _ptr;
	}
private:
	T* _ptr;
};

void TestFunc()
{
	auto_ptr<int> sp1(new int);
	auto_ptr<int> sp2(sp1); //�����ǳ��������ͷŵ�����
	auto_ptr<int> sp3 = sp2;
}
}
#endif

namespace Smart_ptr
{
	//�������ͷ�Ȩ��
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _owner(false)
		{
			if (_ptr)
				_owner = true;
		}

		auto_ptr(const auto_ptr<T>& ap)
			:_ptr(ap._ptr)
			,_owner(ap._owner)
		{
			ap._owner = false;
		}
		auto_ptr<T>& operator=(const auto_ptr<T>& ap)
		{
			if (this == &ap)
				return;
			Release();
			_ptr = ap._ptr;
			_owner = ap._owner;
			ap._ptr = nullptr;
			ap._owner = false;
		}

		T& operator*()const
		{
			return *_ptr;
		}

		T* operator->()const
		{
			return _ptr;
		}

		~auto_ptr()
		{
			Release();
		}
	private:
		void Release()
		{
			if (_ptr && _owner)
				delete _ptr;
		}
	private:
		T* _ptr;
		mutable bool _owner; //��ʾ�ͷ�Ȩ�� mutable��ʾ���޸�
	};

	void TestFunc()
	{
		auto_ptr<int> sp1(new int);
		auto_ptr<int> sp2(sp1);
		auto_ptr<int> sp3 = sp2;
		//�������н���֮�󣬵�������������ֻ��һ����������ͷſռ�
		//���ԣ����Զ������ʵ��һ����Դ
		if (true)
		{
			auto_ptr<int> sp4(sp3);
			//�������������sp4�����ͷţ����к��渳ֵ�Ȳ����޷���������
		}
		//���ܻ����Ұָ�������
		*sp1 = 10;
		*sp2 = 20;
	}
}

#include<memory>

int main()
{
	Smart_ptr::TestFunc();
	unique_ptr<int> up(new int); //һ����Դֻ����һ�����������������
	//unique_ptr<int> up2(up); //error �޷����п�������
	//unique_ptr<int> up3 = up; //error �޷����и�ֵ
	return 0;
}
