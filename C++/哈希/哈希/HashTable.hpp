#pragma once 

#include<vector>
#include<iostream>
using namespace std;

enum State
{EMPTY, EXIST, DELETE};

//设置hash表格中的元素是唯一的，不可重复

template <class T>
struct Elem
{
	Elem(const T& value = T())
	:_value(value)
	{}

	T _value;
	State _state;
};

template<class T>
class HashTable
{
public:
	HashTable(size_t capacity = 10)
		:_ht(capacity)
		, _size(0)
	{
		for (auto& e : _ht)
			e._state = EMPTY;
	}

	bool Insert(const T& value)
	{
		// 需要检测是否需要扩容，哈希冲突越多，哈希效率就会越低
		CheckCapacity();
		size_t hashAddr = HashFunc(value); //取到应当插入的地址
		//检测hashAddr的地址是否可以插入
		while (EMPTY != _ht[hashAddr]._state)
		{
			//发生哈希冲突， 使用线性探测解决
			if (EXIST == _ht[hashAddr]._state && 
				_ht[hashAddr]._value == value)
			{
				return false;
			}

			++hashAddr;
			//hashAddr 走到空间的边界
			if (hashAddr == _ht.capacity())
				hashAddr = 0;
		}
		//找到位置，直接插入
		_ht[hashAddr]._value = value;
		_ht[hashAddr]._state = EXIST;

		_size++;
		return true;
	}

	int Find(const T& value)
	{
		size_t hashAddr = HashFunc(value);
		while (EMPTY != _ht[hashAddr]._state)
		{
			if (EXIST == _ht[hashAddr]._state &&
				value == _ht[hashAddr]._value)
				return hashAddr;
			hashAddr++;
			//找到边界
			if (hashAddr == _ht.capacity())
				hashAddr = 0;

		}
		return -1;
	}

	bool Erase(const T& value)
	{
		int retAddr = Find(value);
		if (-1 != retAddr)
		{
			_ht[retAddr]._state = DELETE;
			_size--;
			return true;
		}

		return false;
	}

private:
	size_t HashFunc(const T& value)
	{
		return value % _ht.capacity();
	}

	void Swap(HashTable<T>& ht)
	{
		_ht.swap(ht._ht);
		swap(_size, ht._size);
	}

	void CheckCapacity()
	{
		//哈希的负载因子：有效元素与容量的比率
		if (_size * 10 / _ht.capacity() >= 7) //_size扩大10倍，用整形进行比较
		{
			HashTable<T> newHT(_ht.capacity() * 2);
			//将原哈希表中的状态为EXIST的元素搬移到新的哈希表中
			for (size_t i = 0; i < _ht.capacity(); i++)
			{
				if (EXIST == _ht[i]._state)
					newHT.Insert(_ht[i]._value);
			}
			Swap(newHT);
		}
	}
private:
	vector<Elem<T>> _ht;  // vector 中存放的是Elem结构体类型元素
	size_t _size; //记录哈希表中有效元素的个数
};

void TestHash()
{
	HashTable<int> ht;
	ht.Insert(4);
	ht.Insert(9);
	ht.Insert(1);
	ht.Insert(3);
	ht.Insert(13);
	ht.Insert(7);
	ht.Insert(12);
	ht.Insert(6);
	ht.Insert(8);
	ht.Insert(18);
	ht.Insert(28);

	cout<<ht.Find(18);
	cout<<ht.Find(10);
	cout<<ht.Erase(4);
}