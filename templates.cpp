#define   _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <string>
#include "Triad.h"
#include "Array.h"
#include "outOfRange.h"


#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

using namespace std;

template <class T>
void my_swap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}


template <class T>
void sort(T* arr, int n)
// sort any array (of length n) of Sortable objects
{
	for (int i = 0; i < n - 1; i++) // selection sort
		for (int j = i + 1; j < n; j++)
			if ((arr[i] < arr[j])) //from "biggest" to "smallest"
			{
				my_swap(arr[i], arr[j]);
			}
};

template <class T>
void print_array(T* arr, int len)
// print any array (of length n) of printable objects
{
	for (int i = 0; i < len; i++) cout << arr[i] << ' ';
}


template <class T>
void print_array(T& arr)
// print an object with len() method on operator []
{
	for (int i = 0; i < arr.len(); i++) cout << arr[i] << ' ';
	cout << endl;
}

template <class T>
void sort(T& arr)
// sort an object with len() method on operator []
{
	for (int i = 0; i < arr.len() - 1; i++) // selection sort
		for (int j = i + 1; j < arr.len(); j++)
			if ((arr[i] < arr[j])) //from "biggest" to "smallest"
			{
				my_swap(arr[i], arr[j]);
			}
};

void test_int_arr() {
	// sorting array of integers
	int arr_int[] = { 4,8,2,6,9,5,3,7,34,5,9,6,4,7 };
	int len = sizeof(arr_int) / sizeof(int);
	cout << "Array of integers:\n";
	print_array(arr_int, len);
	cout << endl;
	sort(arr_int, len);
	cout << "Sorted Array of integers:\n";
	print_array(arr_int, len);
	cout << endl << endl;
}

void test_string_arr() {
	// sorting array of strings (alphabetic order)
	string arr_string[] = { "aaaaa", "222222", "zzzzzzzzzz", "1111", "bbbb" };
	int len = sizeof(arr_string) / sizeof(arr_string[0]);
	cout << "Array of strings:\n";
	print_array(arr_string, len);
	cout << endl;
	sort(arr_string, len);
	cout << "Sorted Array of strings:\n";
	print_array(arr_string, len);
	cout << endl << endl;
}


void test_old_sort_traid_arr() {
	// sorting array of triads
	Triad arr_triad[] = { Triad(1, 2, 3), Triad(7, 6 , 5), Triad(-1, 1, 0) };
	int len = sizeof(arr_triad) / sizeof(arr_triad[0]);
	cout << "Array of triads:\n";
	print_array(arr_triad, len);
	cout << endl;
	sort(arr_triad, len); //also uses my_swap for Triad
	cout << "Sorted Array of triads:\n";
	print_array(arr_triad, len);
	cout << endl << endl;
}
//print Array object
void test_new_print_Array() {
	Array a(8);
	for (int i = 0; i < 8; i++)
		a[i] = i;
	cout << "Print The Array:\n";
	print_array(a);
}

void test_new_sort_Array() {
	//Sort a, and check "sorted" template for object with operator [] and len() method
	Array a(8);
	for (int i = 0; i < 8; i++)
		a[i] = i;
	sort(a);
	cout << "Print Sorted Array:\n";
	print_array(a);
}
//operator [] for non const Array
void test_operator_brackets_for_non_const() {
	Array a1(5);
	a1[0] = 3;
	cout << a1[0] << endl; //prints 3
}
//operator [] for const Array, 'a2[0] = 3;' gives error!
void test_operator_brackets_for_const() {
	const Array a2(5);
	//a2[0] = 3; //is compilation error!
	cout << a2[0] << endl; //prints 0
}

//swap two Arrays
void test_swap_arrays() {
	Array a3(5);
	Array a1(5);
	a3[0] = 6;
	print_array(a3);
	print_array(a1);
	cout << "before" << endl;
	my_swap(a3, a1);
	print_array(a3);
	print_array(a1);
	cout << "after" << endl;
}

void test_throw_string() {
	try {
		Array a1(5);
		a1[10] = 2;
	}
	catch (string& str)
	{
		cout << str << endl;
	}
	catch (outOfRange& oor)
	{
		cout << oor.what() << endl;
	}
}

#define LabVersion 11

//---------------------------------------------------------------------
int main(void)
{
#if LabVersion == 10
	test_int_arr();
	test_string_arr();
	test_old_sort_traid_arr();
	test_new_print_Array();
	test_new_sort_Array();
	test_operator_brackets_for_non_const();
	test_operator_brackets_for_const();
	test_swap_arrays();
#elif LabVersion == 11 

#endif // LabVersion == 10
	test_throw_string();
	cout << "Memory Leaks: " << _CrtDumpMemoryLeaks() << endl;

	return 0;
}

