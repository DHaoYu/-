#include<iostream>
#include<string>

using namespace std;

#if 0
int main()
{
	string s1;
	string s2("hello string");
	string s3(s2);
	string s4(10, 'a');
	string s5("hello world!", 5);
	string s6(s3, 1, 5);
	string s7a(10, 97);
	string s7b(s2.begin(), s2.end());
	return 0;
}
#endif

#if 0
int main()
{
	//= ������������� operator =()
	string str2;//�ڴ������ַ���ʱ����Ҫ�Ƚ����������Ϊһ���ն���
	string s2("hello string");
	string s3(s2);
	string s4 = s3;
	string s5 = "hello";
	str2 = 'x';
	//string s6 = 'c'; error-->ֱ�ӽ��ַ�c�޷�����s6
	string s7 = s5 + s3;
	return 0;
}
#endif

#if 0
int main()
{
	string s("hello bit");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s.empty() << endl;
	
	s.resize(5);
	cout << s << endl;
	s.resize(12, '6');
	cout << s << endl;
	s.resize(20);//���������ÿռ��ǣ�����ռ����ԭ��size�Ļ�����У�
	             //	1. resize<capacity ����������ݣ��������δ��������ַ������Ĭ�ϸ���\0
	s.clear();   // 2. resize>capacity �������ݲ�������vs�����������£���capacity����Ϊ1.5��
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	string s2;
	s2.reserve(20);
	return 0;
}
#endif

#if 0
int main()
{
	string s;
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(50);//�ڽ���reverse����ʱ��������������Ѷ���Ŀռ������С
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	return 0;
}
#endif


