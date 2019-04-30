#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<assert.h>
using namespace std;


class string
{
public:
	//////////////////////////////////
	//construct
	string(const char* str = "")
	{
		if (nullptr == str)
		{
			assert(str);
			return;
		}
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];

		strcpy(_str, str);
	}

	string(const string& s)
	{
		if (this == &s)
			return;

		_size = strlen(s._str);
		_capacity = _size;
		_str = new char[_capacity + 1];

		strcpy(_str, s._str);
	}

	string& operator=(const string& s)
	{
		if (this != &s)
		{
			char* temp = new char[s._size + 1];
			strcpy(temp, s._str);

			delete[] _str;

			_size = s._size;
			_capacity = s._capacity;
			_str = temp;
		}
	}
	~string()
	{
		if (nullptr == _str)
			return;

		_str = nullptr;
		_size = 0;
		_capacity = 0;
	}
	///////////////////////////////////////
	//capacity
	size_t size()
	{
		return _size;
	}

	size_t capacity()
	{
		return _capacity;
	}

	void resize(size_t newSize, char c = 0)
	{
		if (newSize < _capacity)
		{
			if (newSize < _size)
			{
				_size = newSize;
				_str[newSize] = '\0';
			}
			else
				memset(_str + _size, c, newSize - _size);//指针从_tr+_size开始往后++
		}
		else
		{
			while (_capacity < newSize)
				reserve(2 * _capacity);//开辟空间

			memset(_str + _size, c, newSize - _size);
		}
	}

	void reserve(size_t n)
	{
		if (n>_capacity)
		{
			char* ptr = new char[n];
			_str = nullptr;
			swap(_str, ptr);
			_capacity = n;
		}
	}

	bool empty()
	{
		if (_size = 0)
		return false;
		return true;
	}

	void clear()
	{
		_str[0] = '\0';
		_size = 0;
		_capacity = 0;
	}
	////////////////////////////////////////////
	//modify

	string& check_full()
	{
		while (_size <= _capacity)
		{
			reserve(2 * _capacity);
		}
	}

	string& push_back(char c)
	{
		check_full();

		_str[_size ++] = c;
		_str[_size] = '\0';
	}

	string& operator+=(const string& s)
	{
		char* ptr = new char[_size + s._size];
		strcpy(ptr, _str);
		strcpy(ptr + _size, s._str);

		delete[] _str;
		_str = ptr;

		return *this;
	}

	string& operator+=(const char* str)
	{
		char* ptr = new char[strlen(str) + _size];
		strcpy(ptr, _str);
		strcpy(ptr + _size, str);
		delete[] _str;
		_str = nullptr;

		swap(_str, ptr);

		return *this;
	}

	string& operator+=(char c)
	{
		push_back(c);
	}

	string& append(const string& s)
	{
		_size += strlen(s._str);
		check_full();

		strcpy(_str + _size, s._str);

		return *this;
	}

	string& append(const string& s, size_t pos, size_t n)
	{
		if (n > s._size - pos)
			assert(false);

		_size += n;
		check_full();

		for (size_t i = 0; i < n; i++)
		{
			push_back(s._str[pos++]);
		}
	}

	string& append(const char* str)
	{
		_size = strlen(str) + _size;

		check_full();
	}

private:
	char* _str;
	size_t _capacity;
	size_t _size;
};

int main()
{
	return 0;
}   