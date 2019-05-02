#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<assert.h>
using namespace std;

namespace bit
{
	class string
	{
	public:
		typedef char* Iterator;
		friend ostream& operator<< (ostream& _cout, string& s);
	public:
		//////////////////////////////////
		//construct
		string(const char* str = "")
		{
			if (nullptr == str)
			{
				str = "";
				//assert(str);
				//return;
			}
			_size = strlen(str);//一般需要计算\0
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		string(size_t n, char c)
			:_str(new char[n + 1])
			, _size(n)
			, _capacity(n)
		{
			memset(_str, c, _size);
		}

		string(char* str, size_t begin, size_t n)
		{
			char* ptr = new char[n + 1];
			for (size_t i = 0; i < n; i++)
			{
				ptr[i] = str[begin + i];
			}
			_size = n;
			_capacity = _size;
			ptr[n] = '\0';
			_str = ptr;
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
			return *this;
		}
		~string()
		{
			if (nullptr == _str)
				return;

			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		Iterator begin()const
		{
			return _str;
		}


		Iterator end() const
		{
			return _str + _size;
		}
		///////////////////////////////////////
		//capacity
		size_t size()const
		{
			return _size;
		}

		size_t length() const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		void resize(size_t newSize, char c = char())//char() ---给出默认字符
		{
			if (newSize < _capacity)
			{
				if (newSize < _size)
				{
					_size = newSize;
					_str[_size] = '\0';
				}
				else
				{
					memset(_str + _size, c, newSize - _size);//指针从_tr+_size开始往后++
					_size = newSize;
					_str[_size] = '\0';
				}
			}
			else
			{
				while (_capacity < newSize)
					reserve(2 * _capacity);//开辟空间

				memset(_str + _size, c, newSize - _size);
				_size = newSize;
			}
		}

		void reserve(size_t newCapacity)
		{
			if (newCapacity > capacity())
			{
				char* ptr = new char[newCapacity + 1];
				strcpy(ptr, _str);
				delete[] _str;
				_str =ptr;
				_capacity = newCapacity;
			}
			return;
		}

		char& operator[](size_t pos)
		{
			if (pos > size())
				assert(false);

			return _str[pos];
		}
		
		const char& operator[](size_t pos) const
		{
			if (pos > size())
				assert(false);
 
			return _str[pos];
		}


		bool empty()const
		{
			if (_size == 0)
				return false;
			return true;
		}

		void clear()//没有改变空间大小--capacity
		{
			_str[0] = '\0';
			_size = 0;
		}
		////////////////////////////////////////////
		//modify

		string& push_back(char c)
		{
			if (_size == _capacity)
				reserve(2 * _capacity);

			_str[_size++] = c;
			_str[_size] = '\0';
		}

		string& operator+=(const string& s)
		{
			size_t leftByte = _capacity - _size;
			size_t totalByte = s._size + _size;
			
			if (leftByte < s._size)
				reserve(totalByte);

			strcpy(_str + _size, s._str);
			_size += s._size;
			
			return *this;
		}

		string& operator+=(const char* str)
		{
			size_t leftByte = _capacity - _size;
			size_t totalByte = strlen(str) + _size;

			if (leftByte < strlen(str))
				reserve(totalByte);

			strcpy(_str + _size, str);
			_size += strlen(str);

			return *this;
		}

		string& operator+=(char c)
		{
			push_back(c);

			return *this;
		}

		string& append(const string& s)
		{
			*this += s;
			return *this;
		}

		string& append(const string& s, size_t pos, size_t n)
		{
			if (n > s._size - pos)
				assert(false);
			size_t totalByte = n + _size;
			size_t leftByte = _capacity - _size;
			if (leftByte < n)
				reserve(totalByte);

			for (size_t i = 0; i < n; i++)
			{
				push_back(s._str[pos++]);
			}
			_size = totalByte;
			_str[_size] = '\0';

			return *this;
		}

		string& append(const char* str)
		{
			*this += str;

			return *this;
		}

		string& assign(const string& s)
		{
			if (_size < s._size)
				reserve(s._size);
			
			strcpy(_str, s._str);
			_size = s._size;
		
			return *this;
		}

		string& assign(size_t n, char c)
		{
			if (_size < n)
				reserve(n);
			memset(_str, c, n);

			return *this;
		}

		string& assign(const char* str)
		{
			_size = strlen(str);
			strcpy(_str, str);

			return *this;
		}
		//have problem
		string& insert(size_t pos1, const string& s, size_t pos2, size_t n)
		{
			size_t leftByte = _capacity - _size;
			
			if (leftByte < n)
				reserve(_capacity + n);

			_size += s._size;
			for (int i = n; i > 0; i--)
			{
				_str[--_size] = _str[i + pos1];
			}
			for (size_t i = 0; i < n; i++)
			{
				push_back(s._str[pos2 + 1]);
			}
			_str[_size] = '\0';
			return *this;
		}

		string& erase(size_t pos, size_t n)
		{
			if (pos + n >= _size)
			{
				_str[pos] = '\0';
			}
			else
			{
				while (n + pos <= _size)
				{
					_str[pos] = _str[pos + n++];
				}
				_str[pos + n] = '\0';
			}
			return *this;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		const char* c_str()const
		{
			return _str;
		}

		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (c == _str[i])
					return i;
			}
			return -1;
		}

		size_t rfind(char c, size_t npos = -1)const
		{
			for (size_t i =_size; i >0; i--)
			{
				if (c == _str[i])
					return i;
			}
			if (c == _str[0])
				return 0;
			return -1;
		}

		string substr(size_t pos = 0, size_t n = -1) const
		{
			string s(_str, pos, n);
			return s;
		}

	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};

	ostream& operator << (ostream& _cout, string& s)
	{
		_cout << s._str;
		return _cout;
	}
}
void Teststring()
{
	bit::string s1("hello"); 
	bit::string s2(nullptr);
	bit::string s3(s1);
	bit::string s4 = "bit";
	bit::string s5("hello", 2, 3);
	s4 = s3;

	cout << s3 << endl;
}
int main()
{
	Teststring();
	return 0;
}   