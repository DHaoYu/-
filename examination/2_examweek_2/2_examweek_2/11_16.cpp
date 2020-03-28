#define _CRT_SECURE_NO_WARNNINGS1

#if 0
#include<stdio.h>

int main()
{
	printf("\%%\n");
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace  std;

class Printer{
public:
	Printer(string name) { std::cout<< name; }
};
class Container{
public:
	Container() : b("b"), a("a") {}
	Printer a;//按照成员变量的顺序来进行初始化！！！
	Printer b;
};
int main(){
	Container C;
	return 0;
}
#endif

#if 0
template<class T> class Foo{
	T tVar;
public:
	Foo(T t) : tVar(t) { }
};
template<class T> class FooDerived :public Foo<T>
{
public:
	FooDerived(T d)
	:Foo(d)
	{}
};
int main()
{
	FooDerived<int> d(5);//如果父类中存在成员变量，则需要再派生类中显式给出构造
	return 0;
}
#endif
#if 0
//井字棋
#include<vector>
#include<iostream>
using namespace std;

bool checkWon(vector<vector<int> > board) {
	// write code here
	if (board[0][0] + board[1][1] + board[2][2] == 3 ||
		board[0][2] + board[1][1] + board[2][0] == 3)
		return true;
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] + board[i][1] + board[i][2] == 3 ||
			board[0][i] + board[1][i] + board[2][i] == 3)
			return true;
	}
	return false;
}
#endif