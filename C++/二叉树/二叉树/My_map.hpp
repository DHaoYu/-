#pragma once

#include"R-BTree.hpp"

namespace Mymap
{
	template<class K, class V>
	class map
	{
		typedef pair<K, V> DataType;

		struct KeyOfValue
		{
			K operator()(const DataType& val)
			{
				return val.first;
			}
		};

		typedef RBTree<DataType, K, KeyOfValue> RBT;
	public:
		map()
			:_t()
		{}

		//迭代器 iterator
		//typename 告知编译器RBT::iterator 为数据类型而不是静态变量
		typename typedef RBT::iterator iterator;
		iterator begin()
		{
			return  _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		//capacity
		size_t size() const
		{
			return _t.Size();
		}

		bool empty()const
		{
			return _t.Empty();
		}

		//下标访问 access
		V& operator[](const K& key)
		{
			return ((_t.Insert(DataType(key, V())).first))->second;
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
		}
		//修改 modify
		pair<iterator, bool> insert(const DataType& val)
		{
			return _t.Insert(val);
		}
		void swap(map<K, V>& m)
		{
			_t.Swap(m._t);
		}

		void clear()
		{
			_t.Clear();
		}
	private:
		RBTree<DataType, K, KeyOfValue> _t;
	};
}

#include<string>
void TestMap()
{
	Mymap::map<int, string> m;
	m.insert(make_pair(3, "apple"));
	m.insert(make_pair(1, "苹果"));
	m.insert(pair<int, string>(2, "香蕉"));


	cout << m[2] << endl;
	cout << m[1] << endl;
	cout << m[10] << endl;
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "--->" << it->second << endl;
		it++;
	}
	cout << m.size() << endl;
}