#define _CRT_SECURE_NO_WARNNINGS 1
#include<iostream>
using namespace std;

//int main()
//{
//	cout << sizeof(unsigned) << endl;
//	int b[] = { 1, 2, 3, 4 };
//	cout << *b << endl;
//	char acX[] = "abc";//����\0
//	char acY[] = { 'a', 'b', 'c' };//����\0
//	char* szX = "abc";//�����������ݲ����޸�
//	char* szY = "abc";
//	acX[0] = 'z';
//	//szX[1] = 'z';
//	cout << acX[3] << endl;
//	cout << acY[3] << endl;
//	cout << sizeof(acX[0]) << endl;
//	cout << sizeof(acY[0]) << endl;
//	cout << sizeof(szX) << endl;
//	cout << sizeof(szY) << endl;
//	cout << (void*)szX << " " << (void*)szY << endl;
//	//szX[1] = 'z';
//	system("pause");
//}

#if 0
#include<vector>
//����������  1 2 3 2 2 1 ---> ���2��123����221��
//�Ҳ��Ȼ��߲���
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int count = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (arr[i + 1] >= arr[i] && arr[i - 1] > arr[i])
			arr[i + 1] < arr[i] && arr[i - 1] < arr[i])
		{
			count++;
			if(n -1 -2 != i) //��֤β��ʣ����Ԫ�أ����Խ��бȽ�
				i++;
		}
	}
	cout << ++count << endl;
	return 0;
}
#endif

#if 0
//�����ַ��� i like beijing. ---> beijing. like i
#include<string>

int main()
{
	string str;
	getline(cin, str);
	int n = str.size() - 1;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			cout << str.substr(i + 1, n - i)<<" ";
			n = i - 1;
		}
		if (i == 0)
			cout << str.substr(i, n - i + 1) << endl;
	}
	return 0;
}
/*
py3��һ��д����
print(' '.join(input().split(' ')[:: - 1]))#input() Ϊ����
#��һ��' '��join��ʾ������ƴ�ӳ��ַ��������ӷ�Ϊ�ո�
#splist(' ')��ʾ' '���У�[:: - 1]��ʾ�Ӻ���ǰ����
*/
#endif