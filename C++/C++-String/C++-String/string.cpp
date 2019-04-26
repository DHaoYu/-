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

#if 0
int main()
{
	string s("hello bit");
	cout << s[0] << endl;
	cout << s[2] << endl;
	//cout << s[100] << endl； 越界：进行断言判断

	cout << s.at(5) << endl;//成员函数，进行调用需要加上对象名字
	cout << s.at(100) << endl;//越界：进行抛异常操作
	return 0;
}
#endif

#if 0
int main()
{
	//append --->追加
	string s1("hello ");
	string s2("bit!");
	s1 += s2;
	string s3("666");
	s1.append("!!!");
	s2.append(s3, 0, 2);
	s3.append('#', 2);//黑人问号？？？
	cout << s3 << endl;
	s2.append(10,'.');
	s2.append(s1.begin() + 8, s1.end());
	return 0;
}
#endif

#if 0
int main()
{
	//assign --->将原字符内容进行修改
	string s1("hello ");
	s1.push_back('b');
	//s1.push_back("it");//error 实参应为char类型
	s1.push_back('i');
	s1.push_back('t');
	
	string s2("!!");
	s1.assign(s2);
	s1.assign(s2, 1, 1);
	//s1.assign(6, 6);// 黑人问号？？？
	cout << s1 << endl;
	s2.assign("!");
	s1.assign("#", 6);
	s1.assign(3, 'c');
	
	return 0;
}
#endif

#if 0
int main()
{
	string s1("hello ");//什么时候在insert中可以用迭代器？？？
	string s2("bit");
	s1.insert(5, s2);
	s1.insert(0, s2, 0, 1);
	s1.insert(0, "donghaoyu");
	s1.insert(s1.begin(), 6, '!');
	
	s1.erase(s1.begin(), s1.end());
	return 0;
}
#endif

#if 0
int main()
{
	string s1("hello");
	string s2("bit");
	s1.swap(s2);
	string s3, s4;
	s3 = s1.substr(0, 3);
	s4 = s1.substr(0, 10);

	return 0;
}
#endif

#if 0 
void TestString()
{
	string s;
	s.push_back(' ');
	s.append("hello");
	s += 'b';
	s += "it";
	cout << s << endl;
	cout << s.c_str() << endl;
}

void TestStringFile()
{
	string file1("string.cpp");
	size_t pos = file1.rfind('.');
	cout << file1.substr(pos+1,file1.size()) << endl;//截取中间某一段打印
}

void TestStringUrl()
{
	string url("http://www.cplusplus.com/reference/string/string/find/");
	size_t start = url.find("://");
	size_t finish = url.find('/', start + 3);

	cout << url.substr(start + 3, finish - start - 3) << endl;
}
int main()
{
	TestString();
	TestStringFile();
	TestStringUrl();

	return 0;
}
#endif

