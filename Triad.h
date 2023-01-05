#ifndef _TRIAD_H
#define _TRIAD_H

#include <iostream>
using namespace std;

class Triad {
	friend ostream& operator<<(ostream& os, const Triad& triad);
	int _a, _b, _c;
public:
	Triad(){};
	Triad(int a, int b, int c) : _a(a), _b(b), _c(c) {}

	int operator<(const Triad& t) const 
	{ 
		return (_a + _b + _c < t._a + t._b + t._c); 
	}
};
ostream& operator<<(ostream& os, const Triad& triad);
#endif
