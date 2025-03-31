#ifndef _hip_h_
#define _hip_h_
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
using namespace std;

class Hip {
	int m;
	int* key;
	int size;	
	int capacity;

	void clear() {
		delete[]key;
		key = nullptr;
		size = capacity = 0;
	}

	void copy(const Hip& h) {
		key = new int[capacity = h.capacity];
		for (int i = 0; i < h.size; i++)
		{
			key[i] = h.key[i];
		}
	}


	void move(Hip& h) {
		key = h.key;
		m = h.m;
		capacity = h.capacity;
		size = h.size;
		h.key = nullptr;
		h.capacity = h.size = 0;
	}


public:
	Hip(int m, int cap,const char* ime_datoteke);
	Hip(const Hip& h) { copy(h); }
	Hip(Hip&& h) { move(h); }

	Hip& operator=(const Hip& h);
	Hip& operator=(Hip&& h);

	~Hip() { clear(); }

	void init(int m,const char* ime_datoteke);
	void add(int elem, int& steps);
	int get();
	void deletee(int& steps);

	friend ostream& operator<<(ostream& os, const Hip& h);

	Hip convertTo(int newM);
	Hip& unionn(Hip& h2, int& steps);

	void delete_any_elem(int elem);

	int get_size() const { return size; }

};





#endif // !_hip_h_
