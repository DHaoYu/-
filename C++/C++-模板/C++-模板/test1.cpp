#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


#if 0
//����ģ��---��ʹ��ʱ���в����������������ݳ������Ĳ�������
template<class T>//typename�Ƕ���ģ��Ĺؼ��֣�Ҳ����ʹ��class������
void Swap(T a, T b)	//����class����ʹ��struct����
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 1, b = 2;
	Swap(a, b);
	cout << a << b << endl;
	double c = 2.0, d = 1.2;
	Swap(c, d);
	cout << c << d << endl;
	char e = 'a', f = 'b';
	Swap(e, f);
	cout << e << f << endl;
	//Swap(a, c);//����ģ������ֻ��һ�����ͣ������ڴ������ֲ�ͬ���͵Ĳ���ʱ��
	//cout << a << d << endl;//���������޷�������������
	//Swap<int>(e, a);
	Swap(a, (int)c);//ǿת�ı������ܱ�ǿת����������
	return 0;
}
#endif

#if 0
template<class T> 
T Add(const T& left, const T& right) 
{
	return left + right;
}

int main() {
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add(a1, a2);
	Add(d1, d2);
	/*     ����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ
	����Ҫ������ʵ������
	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ�
	��ģ������б���ֻ��һ��T��
	�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
	ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬
	����������Ҫ���ڹ�     Add(a1, d1);    */
	// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 2. ʹ����ʽʵ���� 
	Add(a1, (int)d1);
	return 0;
}
#endif

#if 0
int main()
{
	double b = 1.2;
	int a = 0;
	//int& a = (int)b;
	int& c = a;
	//int e = (int)b;�ɽ���ǿת֮���ȸ�ֵ������int������Ȼ���������
	//int& d = (int)b;error ǿ��ת����ֵ�޷�������
	int& d = (int)b; //�ǳ������õĳ�ʼֵ����Ϊ��ֵ
	//����Ϊ��ֵ������Ϊ��ֵ
	return 0;
}
#endif

#if 0
//����ģ���ʵ����
//��ʽʵ����--->����������ʵ�ε��������ݳ�����ģ�������ʵ������
template<class T>
T Add(const T left, const T right)
{
	return left + right;
}

int main()
{
	cout << Add(1.0, 2.1) << endl;//��ʽʵ����
	return 0;
}
#endif

#if 0
//��ʽʵ����--->�û��Լ��ڵ��ú����ĺ������<Typename���������ͣ�>������ʽʵ����
template<class T>
T Add(const T left, const T right)
{
	return left + right;
}

int main()
{
	Add<double>(1.0, 2.10);
	cout << Add<int>(1.1, 2.10) << endl;//��ʽʵ����������ֱ�ӽ����Ͳ����ϵ�
			//��������ת������Ϊ�������û���д������,�޷�ת���ͻᱨ��
	return 0;
}
#endif 

#if 0
int Add(int left, int right)
{
	return left + right;
}

template<class T>
T Add(T left, T right)//���Դ���ͬ����ģ�庯���ͷ�ģ�庯��
{
	return left + right;
}

int main()
{
	//Add<int>(1.0, 2);//ֻ����ģ����ڵ�����²ſ����������
	cout << Add<double>(1.0, 2.1) << endl;
	cout << Add(1, 2) << endl;//��ģ������һ�£����Ա������������ػ��䣬
					//�����û�д���Ƿ�add����
	return 0;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}


template<class T>
T Add(T left, T right)//���Դ���ͬ����ģ�庯���ͷ�ģ�庯��
{
	return left + right;
}

int main()
{
	cout<<Add(1.1, 2.1);//����ǿ��ת��Ϊint�͵���Add����
	//���������ģ�庯���Ļ�������ģ�庯�����Ը�ƥ������Ͳ��������Ե���ģ�庯��
	return 0;
}
#endif