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

#if 0
int Sum_Solution(int n)//不使用乘除法 for while if else switch case 等关键字
//完成1+2+...+n
{
	//运用递归
	int ans = n;
	ans && (ans += Sum_Solution(n - 1));
	return ans;
}

int main()
{
	cout << Sum_Solution(10) << endl;
	return 0;
}
#endif

#if 0
template<class T>
class Printer
{
public:
	Printer(const T& t)
	:_t(t)
	{}

	void print()
	{
		cout << _t << endl;
	}

private:
	T _t;
};

class empty
{};

int main()
{
	empty e;
	Printer<empty> p(e);//实例化empty类型的p，但是empty中没有重载打印函数，所以
	p.print();//在调用print函数时会出错，但是如果不调用就不会报错。
	//为了节省资源，类模板实例化并不是每个成员函数都生成代码，而是使用到那个成员函数实例化那个成员函数
	return 0;
}
#endif

#include<string>
//类模板别名
//模板的声明只能在全局，命名空间或类中使用***
template<class T> using WithNum = pair<T, int>;//定义了一个pair的偏特化
WithNum<string> strs;//定义了一个pair<string,int> 类型对象strs
int main()
{
	typedef pair<int, int> PairInt;//1 定义了一个别名

	PairInt p;//定义一个pair<int,int> 对象 p
	return 0;
}
