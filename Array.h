//#include <corecrt_memory.h>
//#ifndef _ARRAY_H_
//#define _ARRAY_H_
//#include <string>
//#include <sstream>
//using namespace std;
//template <class T>
//class Array {
//public:
//	Array(int len = 10) : m_len(len), m_data(len ? (new T[len]) : NULL)
//	{
//		if (len)
//			memset(m_data, 0, len * sizeof(T));
//	}
//	~Array() { delete[] m_data; }
//	int len() const { return m_len; }
//	T& operator[](int i);
//	T operator[](int i) const;
//	void FormatExceptionMessage(const int i) const;
//	Array& operator=(const Array& other_arr);
//
//private:
//	int  m_len;
//	T* m_data;
//};
//
//template <class T>
//T& Array<T>::operator[](int i) {
//	if (i > m_len - 1 || i < 0) {
//		FormatExceptionMessage(i);
//	}
//	return m_data[i];
//}
//
//template <class T>
//T Array<T>::operator[](int i) const { //only for const objects
//	if (i > m_len - 1 || i < 0) {
//		FormatExceptionMessage(i);
//	}
//	return m_data[i];
//}
//
//template <class T>
//void Array<T>::FormatExceptionMessage(const int i) const
//{
//	stringstream ss;
//	ss << "Invalid index " << to_string(i) << " in array of length " << to_string(m_len);
//	throw ss.str();
//}
//
//template <class T>
//Array<T>& Array<T>::operator=(const Array<T>& other_arr) {
//	if (&other_arr == this)
//		return *this;
//	if (m_data)
//		delete[] m_data;
//	m_len = other_arr.m_len;
//	if (m_len > 0)
//		m_data = new T[m_len];
//	for (int i = 0; i < m_len; i++) {
//		m_data[i] = other_arr.m_data[i];
//	}
//	return *this;
//}
//
//#endif


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
