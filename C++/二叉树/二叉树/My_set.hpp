#pragma once

#include"R-BTree.hpp"

namespace Myset
{
	template<class K>
	class set
	{
		typedef K DataType;

		struct KeyOfValue
		{
			K operator()(const DataType& val)
			{
				return val;
			}
		};

		typedef RBTree<DataType, K, KeyOfValue> RBT;
	public:
		set()
			:_t()
		{}

		//������ iterator
		//typename ��֪������RBT::iterator Ϊ�������Ͷ����Ǿ�̬����
		typename typedef RBT::iterator iterator;
		iterator begin()
		{
			return  _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		iterator find(const K& key)
		{
			return _t.Find(key);
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

		//�޸� modify
		pair<iterator, bool> insert(const DataType& val)
		{
			return _t.Insert(val);
		}
		void swap(set<K>& m)
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
void TestSet()
{
	Myset::set<int> s;
	int array[] = { 4, 5, 6, 7, 1, 2, 8, 9, 1, 11 };  //1Ϊ�ظ�Ԫ��
	for (auto e : array)
		s.insert(e);
	auto it = s.begin();
	while (it != s.end())
	{
		cout << *it << "--->";
		it++;
	}
	cout << endl << s.size() << endl;
}