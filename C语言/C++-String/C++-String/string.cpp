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
	//= 号运算符的重载 operator =()
	string str2;//在传单个字符的时候，需要先将对象构造出来为一个空对象
	string s2("hello string");
	string s3(s2);
	string s4 = s3;
	string s5 = "hello";
	str2 = 'x';
	//string s6 = 'c'; error-->直接讲字符c无法传入s6
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
	s.resize(20);//当重新设置空间是，如果空间大于原来size的话会进行：
	             //	1. resize<capacity 不会进行扩容，但是如果未给出填充字符，则会默认给成\0
	s.clear();   // 2. resize>capacity 进行扩容操作，在vs编译器环境下，把capacity扩容为1.5倍
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

	s.reserve(50);//在进行reverse操作时，编译器将不会把对象的空间进行缩小
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	return 0;
}
#endif


