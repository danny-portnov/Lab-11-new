#include <corecrt_memory.h>
#ifndef _ARRAY_H_
#define _ARRAY_H_
using namespace std;

class Array {
public:
	Array(int len = 10) : m_len(len), m_data(len ? (new int[len]) : NULL)
	{
		if (len)
			memset(m_data, 0, len * sizeof(int));
	}
	~Array() { delete[] m_data; }
	int len() const { return m_len; }
	int& operator[](int i);
	int operator[](int i) const;
	void FormatExceptionMessage(const int i) const;
	Array& operator=(const Array& other_arr);

private:
	int  m_len;
	int* m_data;
};

#endif
