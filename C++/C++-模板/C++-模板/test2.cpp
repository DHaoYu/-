#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;


#if 0
//��ģ��

template <class T>
class Vector
{
public:
	Vector(size_t capacity)//��ʼ��
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
			//����
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

//�����ⶨ�壬��Ҫ������ģ�������
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
int Sum_Solution(int n)//��ʹ�ó˳��� for while if else switch case �ȹؼ���
//���1+2+...+n
{
	//���õݹ�
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
	Printer<empty> p(e);//ʵ����empty���͵�p������empty��û�����ش�ӡ����������
	p.print();//�ڵ���print����ʱ�����������������þͲ��ᱨ��
	//Ϊ�˽�ʡ��Դ����ģ��ʵ����������ÿ����Ա���������ɴ��룬����ʹ�õ��Ǹ���Ա����ʵ�����Ǹ���Ա����
	return 0;
}
#endif

#include<string>
//��ģ�����
//ģ�������ֻ����ȫ�֣������ռ������ʹ��***
template<class T> using WithNum = pair<T, int>;//������һ��pair��ƫ�ػ�
WithNum<string> strs;//������һ��pair<string,int> ���Ͷ���strs
int main()
{
	typedef pair<int, int> PairInt;//1 ������һ������

	PairInt p;//����һ��pair<int,int> ���� p
	return 0;
}
