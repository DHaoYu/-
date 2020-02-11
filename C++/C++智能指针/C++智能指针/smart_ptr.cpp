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
	//需要显式的写出拷贝构造函数避免深浅拷贝出现的问题
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
// RAII+指针的行为（解引用，->）
void TestFunc()
{
	int *p = new int;
	*p = 10;
	Smartptr<int> sp(new int);
	*sp = 10;
	Smartptr<A> sp2(new A);
	sp2->_a = 10;
	//正确调用方式
	//sp2->->_a = 10; C++进行了优化，省去了第二个箭头
	
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
	//解决浅拷贝问题：深拷贝不行，
	//auto_ptr 在拷贝构造时进行资源转移,不允许多个指针指向同一份资源
	//所以不会造成野指针的问题
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
	auto_ptr<int> sp2(sp1); //会存在浅拷贝多次释放的问题
	auto_ptr<int> sp3 = sp2;
}
}
#endif

namespace Smart_ptr
{
	//增加了释放权力
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
		mutable bool _owner; //表示释放权力 mutable表示可修改
	};

	void TestFunc()
	{
		auto_ptr<int> sp1(new int);
		auto_ptr<int> sp2(sp1);
		auto_ptr<int> sp3 = sp2;
		//函数运行结束之后，调用析构函数，只有一个对象可以释放空间
		//所以，可以多个对象实例一份资源
		if (true)
		{
			auto_ptr<int> sp4(sp3);
			//出了这个作用域，sp4自行释放，所有后面赋值等操作无法正常进行
		}
		//可能会造成野指针的问题
		*sp1 = 10;
		*sp2 = 20;
	}
}

#include<memory>

int main()
{
	Smart_ptr::TestFunc();
	unique_ptr<int> up(new int); //一份资源只能让一个对象管理，不允许共享
	//unique_ptr<int> up2(up); //error 无法进行拷贝构造
	//unique_ptr<int> up3 = up; //error 无法进行赋值
	return 0;
}
