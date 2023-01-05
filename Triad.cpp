#include "Triad.h"


ostream& operator<<(ostream& os, const Triad& triad) {
	os << triad._a << ", " << triad._b << ", " << triad._c << endl;
	return os;
}

//Triad& Triad::operator=(const Triad& other_traid) {
//	_a = other_traid._a;
//}