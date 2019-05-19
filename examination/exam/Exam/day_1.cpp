#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>

using namespace std;


void PrintLevel(int score)
{
	if (score >= 90)
	{
		cout << "VERY_SECURE" << endl;
		return;
	}

	if (score >= 80)
	{
		cout << "SECURE" << endl;
		return;
	}

	if (score >= 70)
	{
		cout << "VERY_STRONG" << endl;
		return;
	}

	if (score >= 60)
	{
		cout << "STRONG" << endl;
		return;
	}

	if (score >= 50)
	{
		cout << "AVERAGE" << endl;
		return;
	}

	if (score >= 25)
	{
		cout << "WEAK" << endl;
		return;
	}

	if (score >= 0)
	{
		cout << "VERY_WEAK" << endl;
		return;
	}

}


int GetLenScore(string& p)
{
	int i = 0;
	while (p[i] != '\0')
	{
		i++;
	}
	if (i <= 4)
		return 5;
	if (i <= 7)
		return 10;
	if (i >= 8)
		return 25;

	return 0;
}

int GetAphScore(string& p)
{
	int i = 0;
	int count1 = 0;
	int count2 = 0;
	while (p[i] != '\0')
	{
		//if ((p[i] <= 'Z' && p[i] >= 'A') || (p[i] <= 'z' &&p[i] >= 'a'))
		if (p[i] <= 'Z' && p[i] >= 'A')
		{
			count1++;
		}
		if (p[i] <= 'z' &&p[i] >= 'a')
		{
			count2++;
		}
		i++;
	}
	if (count1 == i || count2 == i)
		return 10;
	if (count1 != 0 && count2 != 0)
		return 20;

	return 0;
}

int GetNumScore(string& p)
{
	int i = 0;
	int count = 0;
	while (p[i] != '\0')
	{
		if (p[i] >= '0' && p[i] <= '9')
		{
			count++;
		}
		i++;
	}
	if (count == 0)
		return 0;
	if (count == 1)
		return 10;
	return 20;
}

int GetCharScore(string& p)
{
	int i = 0;
	int count = 0;
	while (p[i] != '\0')
	{
		if ((p[i] >= 33 && p[i] <= 47) || (p[i] >= 58 && p[i] <= 64)
			|| (p[i] >= 91 && p[i] <= 96) || (p[i] >= 123 && p[i] <= 126))
			count++;

		i++;
	}
	if (count == 0)
		return 0;
	if (count == 1)
		return 10;
	return 25;
}

int GetRewardScore(int len, int aph, int num, int ch)
{
	if (num != 0 && aph == 20 && ch != 0)
		return 5;
	if (num != 0 && aph == 10 && ch != 0)
		return 3;
	if (num != 0 && aph != 0)
		return 2;
	return 0;
}


void GetPwdLevel(string& p)
{
	int len, aph, num, ch, reward;
	int score = 0;
	len = GetLenScore(p);
	score += len;
	aph = GetAphScore(p);
	score += aph;
	num = GetNumScore(p);
	score += num;
	ch = GetCharScore(p);
	score += ch;
	reward = GetRewardScore(len, aph, num, ch);
	score += reward;
	PrintLevel(score);
}



int main()
{
	char arr[16];
	cin >> arr;
	string pPasswordStr(arr, arr + 16);
	
	GetPwdLevel(pPasswordStr);
	return 0;
}