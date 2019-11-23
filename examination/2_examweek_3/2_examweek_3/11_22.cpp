#define _CRT_SECURE_NO_WARNNINGS 1
//#include<stdio.h>
#if 0
static int a = 1;//ȫ�ֱ���
void fun1(void){
	a = 2;
}
void fun2(void){
	int a = 3;
}
void fun3(void){
	static int a = 4; //�ֲ������������ӳ���������������
}
int main(){
	static int a = 1;
	printf("%d", a);
	fun1();
	printf("%d", a);
	fun2();
	printf("%d", a);
	fun3();
	printf("%d", a);
}
#endif

/*
C++�й��ڶѺ�ջ��˵�����ĸ��Ǵ����:
A �ѵĴ�С���ܲ���ϵͳ�����ƣ�ջ�Ĵ�Сһ��һ���С
B �ڶ���Ƶ���ĵ���new/delete���ײ����ڴ���Ƭ��ջû���������
C �Ѻ�ջ�����Ծ�̬����
D �Ѻ�ջ�����Զ�̬����

ѡC����̬������ָ�ڱ���׶ξ���ȷ����С���ɱ��������з��䣬�Ѳ����Խ��о�̬���䣬�ѵ����붼����ִ�й����н��еġ�
A���Ѻ�ջ�Ĵ�С���������ã�ջһ��ֻ�м�KB��
B�����ڶ�̬����ʱ��Ҫ�����������ڴ�ռ䣬�ͷź�������Ƭ��
D������ʹ��malloc()��calloc()��realloc()�Ⱥ�����̬����ģ���ʹ��alloca()�������Զ�̬����ջ���ڴ�ռ䣬�ͷŵ�ʱ���ɱ������Լ��ͷ�
*/
#if 0
#include<iostream>
using namespace std;
/*
//��������----��λ����
int main()
{
int x;
while(cin>>x)
{
int count = 0;
while(x)
{
if(x & 1 == 1)
count++;
x>>=1;
}
cout<<count<<endl;
}
return 0;
}
*/
#include<bitset>
int main()
{//ʹ��bitset
	int n;
	while (cin >> n){
		bitset<32> bs(n);
		cout << bs.count() << endl;
	}
}
#endif

#if 0
#include<iostream>
#include<vector>
using namespace std;
/*
1. �Ȱ�����Ϊ0��ƥ��϶����ɹ��ģ�����������ȫ���ó���
2. �ҳ�������������С�ͣ�������0���׵ģ����飬�Ѹ�������������������
   ȫ���ˣ�ʣ����С�ģ���һ��
3. �ٴӶ�������У��ó����һ�����Ϳ���ƥ��
*/
int findMinimum(int n, vector<int> left, vector<int> right)
{
	int min = 0, lmin = 0, rmin = 0;
	int lm = 27, rm = 27;
	for (int i = 0; i < n; i++)
	{
		if (left[i] == 0 || right[i] == 0)
		{
			min += left[i];
			min += right[i];
		}
		else
		{
			lmin += left[i];
			rmin += right[i];
			if (left[i] < lm)
				lm = left[i];
			if (right[i]< rm)
				rm = right[i];
		}
	}
	min += lmin > rmin ? (rmin - rm) : (lmin - lm);
	return min + 2;
}

int main()
{
	//8,[2,1,1,4,7,2,3,1],[0,0,0,1,0,1,0,0] ---18
	vector<int> left = { 2, 1, 1, 4, 7, 2, 3, 1 };
	vector<int> right = { 0, 0, 0, 1, 0, 1, 0, 0 };
	cout << findMinimum(8, left, right) << endl;
	vector<int> left1 = { 0, 7, 1, 6 };
	vector<int> right1 = { 1, 5, 0, 6};
	cout << findMinimum(4, left1, right1);
}
#endif