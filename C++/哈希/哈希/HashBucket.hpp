#pragma once


template<class T>
struct HBNode
{
	HBNode(const T& data)
	: _data(data)
	, _pNext(nullptr)
	{}
	HBNode<T>* _pNext;
	T _data;
};


template<class V>
class HashBucket
{
	typedef HBNode<V> Node;
public:
	HashBucket(size_t capacity = 10)
		:_table(capacity, nullptr)
		, _size(0)
	{}

	~HashBucket()
	{
		Clear();
	}

	bool Insert(const V& data)
	{
		CheckCapacity();  //�������
		//���㵱ǰԪ����Ҫ�����Ͱ��
		size_t BucketNo = HashFunc(data);
		//����Ԫ���Ƿ���Ͱ�У���������
		Node* pCur = _table[BucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return false;
			pCur = pCur->_pNext;
		}
		//����
		pCur = new Node(data);
		pCur->_pNext = _table[BucketNo];
		_table[BucketNo] = pCur;
		++_size;

		return true;
	}

	Node* Find(const V& data)
	{
		size_t BucketNo = HashFunc(data);
		Node* pCur = _table[BucketNo];
		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;
			pCur = pCur->_pNext;
		}
		return nullptr;
	}

	bool Erase(const V& data)
	{
		size_t BucketNo = HashFunc(data);
		Node* pCur = _table[BucketNo];
		Node* pPre = nullptr;
		while (pCur)
		{
			if (pCur->_data == data)
			{ //�ҵ���ɾ���ڵ�
				if (nullptr == pPre)
				{ //��ɾ������ǵ�һ�����	
					_table[BucketNo] = pCur->_pNext;
				}
				else
				{ //���ǵ�һ�����
					pPre->_pNext = pCur->_pNext;
				}
				delete pCur;
				_size--;
				return true;
			}

			pPre = pCur;
			pCur = pCur->_pNext;
		}
		return false;
	}

	size_t Size() const
	{
		return _size;
	}

	void Clear()
	{
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); bucketNo++)
		{
			Node* pCur = _table[bucketNo];
			while (pCur)
			{
				_table[bucketNo] = pCur->_pNext;
				delete pCur;
				pCur = _table[bucketNo];
			}
		}
		_size = 0;
	}

private:
	size_t HashFunc(const V& data)
	{
		return data % _table.capacity();
	}

	void Swap(HashBucket<V>& newHB)
	{
		_table.swap(newHB._table);
	}

	void CheckCapacity()
	{
		if (_size == _table.capacity())
		{
			HashBucket<V> newHB(2 * _size);
			for (size_t BucketNo = 0; BucketNo < _table.capacity(); BucketNo++)
			{
				Node* pCur = _table[BucketNo];
				while (pCur)
				{ 
					//ȱ�㣺��Ҫ���´�����㣬������࣬Ч�ʻ��
					//newHB.Insert(pCur->_data); 
					//pCur = pCur->_pNext;
					
					//����ʵ��һ��������Ĳ��뺯��
					size_t newBucketNo = newHB.HashFunc(pCur->_data);
					_table[BucketNo] = pCur->_pNext;

					pCur->_pNext = newHB._table[newBucketNo];
					newHB._table[newBucketNo] = pCur;

					pCur = _table[BucketNo];
				}
			}
			Swap(newHB);
		}
	}
private:
	vector<HBNode<V>*> _table;
	size_t _size;
};

void TestBucket()
{
	HashBucket<int> hb(4);
	int arr[] = { 1, 11, 12, 32, 33, 44, 4, 6, 19, 8, 21 };
	for (auto e : arr)
		hb.Insert(e);

	cout << hb.Find(4)->_data << endl;
	cout << hb.Find(21)->_data << endl;

	hb.Erase(1);
	hb.Clear();
}