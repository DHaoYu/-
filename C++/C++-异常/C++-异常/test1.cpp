#include<iostream>
#include<typeinfo>

using namespace std;

#if 0 
//test bad_typeid
class Base
{
public:
	virtual void Func()
	{}
};

int main()
{
	try
	{
		Base *bp = 0;
		cout << typeid(*bp).name() << endl;
	}
	catch (exception& bt)
	{
		cerr << "bad_typeid caught: " << bt.what() << endl;
	}
}
#endif

#if 0
class Base
{
public:
	virtual void Func()
	{}
};
class Derived : public Base
{};
int main()
{
	try
	{
		Base b;
		Derived& rd = dynamic_cast<Derived&>(b);
	}
	catch (exception& bc)
	{
		cerr << "bad_cast caught: " << bc.what() << endl;
	}
}
#endif

#if 0
int main()
{
	try
	{
		int * arr;
		while(1)
			arr = new int[100000000];
	}
	catch (exception& ba)
	{
		cerr << "bad_alloc caugth: " << ba.what() << endl;
	}
}

#endif
#if 0
#include<vector>
int main()
{
	vector<int> v(10);
	try
	{
		v.at(20) = 10;
	}
	catch (exception& oor)
	{
		cerr << "out_of_range caugth: " << oor.what() << endl;
	}
}
#endif

#if 0
int main()
{
	int* arr;
	try
	{
		arr = new int[10];
	}
	catch (exception& oor)
	{
		cerr << "run_time caugth: " << oor.what() << endl;
	}
}
#endif
#if 0
#include<bitset>
int main()
{
	try
	{
		bitset<5> set(string("01234"));
	}
	catch (exception& ia)
	{
		cerr << "run_time caugth: " << ia.what() << endl;
	}
}
#endif


#include <vector>
int main() 
{
	try {
		vector<int> myvector;
		myvector.resize(myvector.max_size() + 1);
	}
	catch (length_error& le) {
		cerr << "Length error: " << le.what() << endl;
	}
	return 0;
}