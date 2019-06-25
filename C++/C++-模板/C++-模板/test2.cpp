#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;


#if 0
//类模板

template <class T>
class Vector
{
public:
	Vector(size_t capacity)//初始化
	:pData(new T[capacity])
	, _size(0)
	, _capacity(capacity)
	{
		cout << "Vector():" << this << endl;
	}

	void push_back(T data)
	{
		if (_size == _capacity)
		{
			//扩容
		}
		pData[_size] = data;
		_size+=1;
	}
	size_t size()
	{
		return _size;
	}

	T& operator[](size_t pos)
	{
		assert(pos < _size);
		return pData[pos];
	}

	~Vector();
private:
	T* pData;
	size_t _size;
	size_t _capacity;
};

//在类外定义，需要加上类模板的声明
template<class T>
Vector<T>::~Vector()
{
	if (pData)
	{
		cout << "~Vector():" << this << endl;
		delete[] pData;
	}
}

int main()
{
	Vector<int> v1(10);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";

	}

	Vector<double> v2(10);
	v2.push_back(1.1);
	v2.push_back(2.2);
	v2.push_back(3.3);
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v2[i] << " ";

	}
	return 0;
}
#endif