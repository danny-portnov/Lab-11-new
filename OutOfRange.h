#ifndef _OUTOFRANGE_H_
#define _OUTOFRANGE_H_
#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

class outOfRange : public exception
{
public:
	outOfRange(int len, int index ) : m_len(len), m_index(index) {}
	~outOfRange() {}
	virtual const char* what() const throw()
	{
		stringstream ss;
		ss << "Invalid index " << to_string(m_index) << " in array of length " << to_string(m_len);
		const string& tmp = ss.str();
		const char* cstr = tmp.c_str();
		return cstr;
	}
private:
	int m_len;
	int m_index;
};



//class OutOfRange {
//public:
//	Array(int len = 10) : m_len(len), m_data(len ? (new int[len]) : NULL)
//	{
//		if (len)
//			memset(m_data, 0, len * sizeof(int));
//	}
//	~Array() { delete[] m_data; }
//	int len() const { return m_len; }
//	int& operator[](int i);
//	int operator[](int i) const;
//	Array& operator=(const Array& other_arr);
//
//
//private:
//	int  m_len;
//	int* m_data;
//};

#endif
