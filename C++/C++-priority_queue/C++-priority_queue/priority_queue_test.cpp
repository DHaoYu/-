#include<queue>
#include<iostream>
using namespace std;

#if 0
int main()
{
	priority_queue<int> p;
	p.push(1);
	p.push(10);
	p.push(13);
	p.push(21);
	p.push(8);
	p.push(7);
	while (!p.empty())
	{
		cout << p.top() << endl;
		p.pop();
	}
}
#endif


#if 0
typedef struct Node
{
	Node(const int& fir = 1, const int& sec = 2)
	: first(fir)
	, second(sec)
	{}

	bool operator<(const Node& n) const
	{
		return first < n.first;
	}

	int first; 
	int second;
}node;

void func()
{
	priority_queue<Node> q;
	node n1(10, 100);
	node n2(4, 40);
	node n3(1, 10);
	node n4(15, 150);
	q.push(n1);	q.push(n2);	q.push(n3);	q.push(n4);
}
int main()
{
	func();
}

#endif
