#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<assert.h>
#include<algorithm>

using namespace std;

namespace bit
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* ConstIterator;
	public:
////////////////////construct
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}

		vector(size_t n, const T& data = T())
			:_start(new T[n])
			, _finish(_start + n)
			, _endOfStorage(_finish)
		{
			for (size_t i = 0; i < n; i++)
			{
				_start[i] = data;
			}
		}

		vector(T* first, T* last)
			:_start(new T[last - first])
			, _finish(_start + (last - first))
			, _endOfStorage(_finish)
		{
			size_t size = last - first;

			for (size_t i = 0; i < size; i++)
				_start[i] = first[i];
		}

		vector(const vector<T>& v)
		{
			_start = new T[v.size()];
			for (size_t i = 0; i < v.size(); i++)
				_start[i] = v._start[i];

			_finish = _endOfStorage = _start + v.size();
		}

		vector<T>& operator = (const vector<T>& v)
		{
			_start = new T[v.size()];
			for (size_t i = 0; i < v.size(); i++)
				_start[i] = v._start[i];

			_finish = _start + v.size();
			_endOfStorage = _finish;

			return *this;
		}

		~vector()
		{
			if (_start)
				delete[] _start;

			_start = _finish = _endOfStorage = nullptr;
		}
/////////////////////capacity
		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _endOfStorage - _start;
		}

		bool empty()const
		{
			if (_finish)
				return false;

			return true;
		}

		void resize(size_t sz, const T& data = T())
		{
			if (sz <= size())
			{
				_finish = sz + _start;
			}
			else
			{
				if (sz > capacity())
					reserve(sz);

				for (size_t i = size(); i < sz; i++)
				{
					*_finish++ = data;
				}
				_finish = _start + sz;
			}
		}

		void reserve(size_t newCapacity)
		{
			if (newCapacity == capacity())
				newCapacity = 1;
			if (newCapacity > capacity())
			{
				T* ptr = new T[newCapacity];

				for (size_t i = 0; i < size(); i++)
				{
					ptr[i] = _start[i];
				}
				size_t length = size();//先将其size()内容保存备份
				delete[] _start;//在释放_start 空间时，会将vector对象中的size和其他内容改变
				_start = ptr;
				_finish = length + _start;
				_endOfStorage = _start + newCapacity;
			}
		}

		T& operator[](size_t n)
		{
			assert(n < size());
			return _start[n];
		}

		const T& operator [](size_t n)const
		{
			assert(n < size());
			return _start[n];
		}

		T& front()
		{
			return _start[0];
		}

		const T& front()const
		{
			return _start[0];
		}

		T& back()
		{
			//return _start[_finish - _start];
			return *(_finish - 1);
		}

		const T& back()const
		{
			return _start[_finish-_start];
		}
////////////////iterator
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		ConstIterator Cbegin()const
		{
			return _start;
		}
		
		ConstIterator Cend()const
		{
			return _finish;
		}

/////////////////modify
		void push_back(const T& data)
		{
			if (_finish == _endOfStorage)
				reserve(2 * capacity());

			*_finish++ = data;
		}
		
		void pop_back()
		{
			if (_start == _finish)
				return;

			finish--;
		}

		iterator insert(iterator pos, const T& data)
		{
			assert(pos - _finish);
			size_t n = pos - _start;
			if (_finish == _endOfStorage)
				reserve(2 * capacity());

			for (size_t i = size(); i >= size() - n; i--)
				_start[i + 1] = _start[i];

			_start[n] = data;
			_finish++;
			return pos;
		}

		iterator erase(iterator pos)
		{
			for (size_t i = pos - _start; i < size(); i++)
				_start[i] = _start[i + 1];
			_finish--;
			return pos;
		}

		iterator erase(iterator first, iterator last)
		{
			if (first < begin())
				first = begin();
			if (last > end())
				last = end();

			size_t interval = last - first + 1;//1~3区间为三个值，所以区间需要加一
			size_t begin = first - _start;
			for (size_t i = last - _start + 1; i < size(); i++)
			{
				_start[begin++] = _start[i];
			}
			_finish -= interval;
			return first;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}

		void clear()
		{
			_finish = _start;
		}

	private:
		T* _start;
		T* _finish;
		T* _endOfStorage;
	};
}

void PrintVector(const bit::vector<int>& v)
{
	bit::vector<int>::ConstIterator it = v.Cbegin();//形参为const类型，只能调用const类型成员函数
	while (it != v.Cend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

#if 0
int main()
{
	bit::vector<int> v1;
	bit::vector<int> v2(5, 10);
	int array[] = { 1, 2, 3, 4, 5, 6, 7 };
	bit::vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));
	bit::vector<int> v4(v3);
	v1 = v2;
	
	PrintVector(v1);
	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);

	v4.push_back(8);
	PrintVector(v4);

	bit::vector<string> strV;
	strV.push_back("1111");
	strV.push_back("2222");
	strV.push_back("3333");
	strV.push_back("4444");
	for (size_t i = 0; i < strV.size(); ++i)    
	{
		cout << strV[i] << " ";
	}   
	cout << endl;
	return 0;
}
#endif

#if 0
int main()
{
	bit::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	it = v.begin();
	while (it != v.end())
	{
		*it *= 2;//必须为一个可以修改的it，非const类型
		++it;
	}
	PrintVector(v);
	return 0;
}
#endif

#if 0
int main()
{
	size_t size;
	bit::vector<int> v;
	v.push_back(1);
	size = v.capacity();
	cout << v.capacity() << endl;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
		if (size != v.capacity())
		{
			size = v.capacity();
			cout << v.capacity() << endl;
		}
	}
	return 0;
}
#endif

#if 0
int main()
{
	bit::vector<int> v1;
	cout << v1.capacity() << endl;
	v1.reserve(100);
	cout << v1.capacity() << endl;
	v1.reserve(10);
	cout << v1.capacity() << endl; 

	return 0;
}
#endif

#if 0
int main()
{
	bit::vector<int> v2;
	for (int i = 0; i <= 10; i++)
		v2.push_back(i);
	cout << v2.size() << endl;

	v2.resize(5);
	auto it = v2.begin();
	while (it != v2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;

	v2.resize(10);
	it = v2.begin();
	while (it != v2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;

	v2.resize(100, 2);
	it = v2.begin();
	while (it != v2.end())
	{
		//cout << *it << " ";
		it++;
	}
	cout << endl;	
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;

	return 0;
}
#endif

#if 0
int main()
{
	int array[] = { 1, 2, 3, 4 };
	bit::vector<int> v(array, array + sizeof(array) / sizeof(array[0]));
	auto it = find(v.begin(), v.end(), 3);//find 函数为<algorithm>库函数内的迭代器调用该函数
	cout << *it << endl;
	v.insert(it, 30);
	PrintVector(v);
	//处理迭代器失效问题
	//防止迭代器失效 it需要重置
	it = find(v.begin(), v.end(), 3);
	v.erase(it);
	PrintVector(v);
	v.push_back(10);
	v.push_back(10);
	v.push_back(10);
	PrintVector(v);
	v.erase(v.begin(), v.begin() + 2);
	PrintVector(v);

	return 0;
}
#endif

#if 0
int main()
{
	int array[] = { 1, 2, 3, 4 };
	bit::vector<int> v(array, array + sizeof(array) / sizeof(array[0]));
	v[0] = 10;
	cout << v[0] << endl;
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	bit::vector<int> swapv;
	swapv.swap(v);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < swapv.size(); i++)
	{
		cout << swapv[i] << " ";
	}
	cout << endl;

	return 0;
}
#endif

