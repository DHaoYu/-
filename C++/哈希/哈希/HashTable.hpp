#pragma once 

#include<vector>
#include<iostream>
using namespace std;

enum State
{EMPTY, EXIST, DELETE};

//����hash����е�Ԫ����Ψһ�ģ������ظ�

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
		// ��Ҫ����Ƿ���Ҫ���ݣ���ϣ��ͻԽ�࣬��ϣЧ�ʾͻ�Խ��
		CheckCapacity();
		size_t hashAddr = HashFunc(value); //ȡ��Ӧ������ĵ�ַ
		//���hashAddr�ĵ�ַ�Ƿ���Բ���
		while (EMPTY != _ht[hashAddr]._state)
		{
			//������ϣ��ͻ�� ʹ������̽����
			if (EXIST == _ht[hashAddr]._state && 
				_ht[hashAddr]._value == value)
			{
				return false;
			}

			++hashAddr;
			//hashAddr �ߵ��ռ�ı߽�
			if (hashAddr == _ht.capacity())
				hashAddr = 0;
		}
		//�ҵ�λ�ã�ֱ�Ӳ���
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
			//�ҵ��߽�
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
		//��ϣ�ĸ������ӣ���ЧԪ���������ı���
		if (_size * 10 / _ht.capacity() >= 7) //_size����10���������ν��бȽ�
		{
			HashTable<T> newHT(_ht.capacity() * 2);
			//��ԭ��ϣ���е�״̬ΪEXIST��Ԫ�ذ��Ƶ��µĹ�ϣ����
			for (size_t i = 0; i < _ht.capacity(); i++)
			{
				if (EXIST == _ht[i]._state)
					newHT.Insert(_ht[i]._value);
			}
			Swap(newHT);
		}
	}
private:
	vector<Elem<T>> _ht;  // vector �д�ŵ���Elem�ṹ������Ԫ��
	size_t _size; //��¼��ϣ������ЧԪ�صĸ���
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