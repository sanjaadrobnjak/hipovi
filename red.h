#ifndef _red_h_
#define _red_h_

#include "hip.h"
#include <iostream>
using namespace std;

class Red {
	Hip hip;

public:
	Red(int size, int M, const char* ime_datoteke) : hip(M, size, ime_datoteke) {}


	void remove() { 
		int s = 0;
		hip.deletee(s); 
	}

	Red& insert(int k) {
		int s = 0;
		hip.add(k, s); 
		return *this;
	}

	bool is_empty() const { return hip.get_size() == 0; }

	void dohvati_prvi_elem() {
		cout<< hip.get();
	}

};

#endif // !_red_h_
