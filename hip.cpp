#include "hip.h"
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
using namespace std;

Hip::Hip(int M, int cap,const char* ime_datoteke)
{
	capacity = cap;
	size = 0;
	key = new int[cap];
	m = M;
	
	for (int i = 0; i < cap; i++)
	{
		key[i] = 0;
	}

	init(m,ime_datoteke);
}

Hip& Hip::operator=(const Hip& h)
{
	if (this != &h) {
		clear();
		copy(h);
	}
	return *this;
}

Hip& Hip::operator=(Hip&& h) {
	if (this != &h) {
		clear();
		move(h);
	}
	return *this;
}

void Hip::init(int m, const char* ime_datoteke) {	
	FILE* fp = fopen(ime_datoteke, "r");
	if (fp == NULL) {
		printf("Ne postoji datoteka %s!\n", ime_datoteke);
		exit(1);
	}
	if (capacity < 1) return;
	
	
	int cnt = 0;
	while (true)
	{
		int elem;
		fscanf(fp, "%d", &elem);

		if (feof(fp)) {
			break;
		}
		int x = 0;
		add(elem, x);
		cnt++;
	}

	fclose(fp);
}

void Hip::add(int elem, int& steps) {
	
	if (size == capacity) {
		capacity = capacity * 2;
	}


	key[size] = elem;
	int f = (size - 1) / m;
	int tmp = size;

	while (true)
	{
		if (elem < key[f]) {
			int pom = key[f];
			key[f] = key[tmp];
			key[tmp] = pom;
			steps = steps + 2;
			tmp = f;
			f = (f - 1) / m;		
		}
		else
		{	
			steps++;
			break;
		}
	}
	size++;
}

ostream& operator<<(ostream& os, const Hip& h)
{
	for (int i = 0; i < h.size; i++)
	{
		if (h.key[i] != 0) {
			os << h.key[i] << " ";
		}	
	}
	os << endl;

	int ii = 0;
	int f = 0;
	int prvi_sin = 1;
	while (ii<h.size)
	{
		
		os << "Otac je " << h.key[ii] << ". Njegovi sinovi su: ";
		for (int i = 0; i < h.m; i++)
		{
			os << h.key[prvi_sin + i]<<" ";
		}


		if (h.key[prvi_sin] == 0) {
			os << "cvorovi su listovi, nemaju decu";
			break;
		}
		os << endl;
		
		ii++;
		prvi_sin = h.m * ii + 1;
	}

	return os;
}

int Hip::get() {
	int min = key[0];
	for (int i = 1; i < size; i++)
	{
		if (key[i] != 0 && key[i] < min) {
			min = key[i];
		}
	}
	return min;
}

void Hip::deletee(int& steps) {
	int pom = key[size - 1];
	key[size - 1] = key[0];
	key[0] = pom;
	key[size - 1] = 0;
	size--;

	int f = 0;
	int prvi_sin = 1;
	int min, s, br;
	while (true) {

		for (int j = 0; j < m; j++)
		{
	
			if (key[f] > key[prvi_sin + j])
			{
				steps++;
				s = prvi_sin + j;
				min = key[s];
				int ii = j;
				br = s;
				while (ii < m)
				{
					if (min > key[s] && key[s]!=0) {
						min = key[s];
						br = s;
					}
					s++;
					ii++;
					steps++;
				}


				int pom = key[f];
				key[f] = key[br];
				key[br] = pom;
				steps++;

				break;

			}
		}
		prvi_sin = m * br + 1;
		f = (prvi_sin - 1) / m;

		if (key[prvi_sin] == 0) {
			break;
		}
	}

	
}

Hip Hip::convertTo(int newM) {
	Hip h(newM, 150, "test10.txt");
	return h;	
}


Hip& Hip::unionn(Hip& h2, int& steps) {
	
	for (int i = 0; i < h2.size; i++)
	{
		add(h2.key[i], steps);
		
	}
	return *this;	
}


void Hip::delete_any_elem(int elem) {
	int tmp = 0;
	while (elem != key[tmp]) {
		tmp++;
	}

	int pom = key[tmp];
	key[tmp] = key[size - 1];
	key[size - 1] = pom;
	key[size - 1] = 0;
	size--;


	int otac = (tmp - 1) / m;
	int prvi_sin = m * tmp + 1;
	int min, s, br;

	if (key[tmp] < key[otac]) {
		while (true)
		{
			if (key[tmp] < key[otac]) {
				pom = key[otac];
				key[otac] = key[tmp];
				key[tmp] = pom;
				//steps = steps + 2;
				tmp = otac;
				otac = (otac - 1) / m;
			}
			else
			{
				//steps++;
				break;
			}
		}
	}
	else
	{
		
		while (true) {

			for (int j = 0; j < m; j++)
			{

				if (key[tmp] > key[prvi_sin + j])
				{
					//steps++;
					s = prvi_sin + j;
					min = key[s];
					int ii = j;
					br = s;
					while (ii < m)
					{
						if (min > key[s] && key[s] != 0) {
							min = key[s];
							br = s;
						}
						s++;
						ii++;
						//steps++;
					}

					pom = key[tmp];
					key[tmp] = key[br];
					key[br] = pom;
					//steps++;
					break;
				}
			}
			prvi_sin = m * br + 1;
			tmp = (prvi_sin - 1) / m;

			if (key[prvi_sin] == 0) {
				break;
			}
		}
	}

}
