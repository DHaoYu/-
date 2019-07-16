#define _CRT_SECURE_NO_WARNNINGS 1
#include<string>
#include<iostream>
using namespace std;

#if 0
template<class T>
class Printer
{
public:
	Printer(T& t)
		:_t(t)
	{}

	string&& to_string();//�������ⲿ

	void print()//�������ڲ�
	{
		cout << _t << endl;
	}
private:
	T _t;
};

template<class T>
string&& Printer<T>::to_string()
{
	strstream ss;
	ss << t;
	return std::move(string(ss.str()));
}

int main()
{
	//Printer p(1);error û��ʵ��������
	int a = 10;
	Printer<int> p1(1);//��������Ϊ��������Ҫ���ó��������뽫����������const���Ρ�
	Printer<int> p(a);
	return 0;
}
#endif

#if 0
class Printer
{
public:
	Printer(int& t)//��������£��������ó�������Ϊ�������ڴ��д洢λ���ڳ�����
		:_t(t)
	{}

private:
	int _t;
};

int main()
{
	Printer p1(12);//
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


	template<class U>
	void print(const U& u)//�������ڲ�
	{
		cout << u << endl;//��Ա����ģ������������ݽ�����ʽʵ����
		cout << _t << endl;
	}
private:
	T _t;
};


int main()
{
	Printer<int> p(1);
	p.print('a');
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

	void print()//�������ڲ�
	{
		cout << _t << endl;
	}
public:
	static int _val;
private:
	T _t;
};

template<class T>
int Printer<T>::_val = 1;//��̬��Ա��Ҫ��������г�ʼ������ʼ��ʱ��Ҫ����ģ�����T
//���е��������������ⶨ��ʱ����Ҫ����

int main()
{
	Printer<int> pi1(1);
	Printer<int> pi2(2);
	Printer<double> pd1(1.1);
	cout << &pi1._val << endl;//pi1��pi2ʵ������������ͬ����ʼ��ʱ����һ��static��Ա����
	cout << &pi2._val << endl;
	cout << &pd1._val << endl;//pd1�������double���ͣ����������е�double���Ͷ����У�����һ��
	return 0;
}
#endif

#if 0
//Ĭ��ʵ��
template<class T,class F = less<T>>
int compare(const T& left, const T& right, F f = F())//�����������󣬸�ֵ��f
{
	if (f(left, right))//����f���캯��
	{
		cout << "left" << endl;
	}
	if (f(right, left))
	{
		cout << "right" << endl;
	}
	return 0;
}

int main()
{
	compare(1, 2);
	compare(3, 2);
	return 0;
}
#endif

