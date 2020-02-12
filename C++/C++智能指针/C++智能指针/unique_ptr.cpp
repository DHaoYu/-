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

#if 0
namespace smart_ptr
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr = nullptr)
		:_ptr(ptr)
		{}

		unique_ptr(unique_ptr& up)
			:_ptr(up._ptr)
		{
			up._ptr = nullptr;
		}

		unique_ptr& operator=(unique_ptr& up)
		{
			if (this != &up)
			{
				_ptr = up._ptr;
				up._ptr = nullptr;
			}
		}

		T& operator*()const
		{
			return *_ptr;
		}
		
		T* operator->()const
		{
			return _ptr;
		}

		void reset(T* p)
		{
			if (_ptr)
				delete _ptr;
			_ptr = p;
		}

		void swap(unique_ptr& up)
		{
			if (this != &up)
			{
				std::swap(_ptr, up._ptr);
			}
		}

		T* get()
		{
			return _ptr;
		}

		~unique_ptr()
		{
			if (_ptr)
				delete _ptr;
		}
	private:
		T* _ptr;
	};

	void Testfunc()
	{
		unique_ptr<int> up1(new int);
		*up1 = 10;
		unique_ptr<int> up2(up1);
		*up2 = 20;
		unique_ptr<int> up3;
		up3.reset(new int);
		*up3 = 10;
		up3.swap(up2);
		auto ptr = up3.get();
		*ptr = 30;
	}
}

int main()
{
	smart_ptr::Testfunc();
	return 0;
}
#endif