#include "hip.h"
#include "red.h"

#include <iostream>
#include <string>
using namespace std;

#include <chrono>
#include <thread>
using namespace std::chrono;

int main() {
	
	cout << "1. M-arni hip"<<endl;
	cout << "2. Prioritetni red" << endl;
	cout << "Izaberite da li zelite da radite sa m-arnim hipom ili sa prioritetnim redom: ";
	int nesto;
	cin >> nesto;
	cout << endl << endl;

	if (nesto == 1) {
		int m;
		cout << "Unesite red m-arnog hipa: ";
		cin >> m;
		cout << "M-arni hip reda " << m << " je napravljeno!" << endl;
		Hip h(m, 120, "test10.txt");
		Hip h2(m, 120, "proba.txt");

		int stp, stepic, s, elem, e, new_m;

		cout << endl;
		cout << "1. Dodavanje elementa u hip" << endl;
		cout << "2. Dohvatanje minimalnog elementa hipa" << endl;
		cout << "3. Brisanje minimalnog elementa iz hipa" << endl;
		cout << "4. Pretvaranje hipa u hip zadatog novog reda" << endl;
		cout << "5. Dodavanje jednog hipa drugom" << endl;
		cout << "6. Ispis hipa" << endl;
		cout << "7. Unistavanje hipa" << endl;
		cout << "8. Brisanje proizvoljnog elementa" << endl;
		cout << "9. Kraj programa" << endl;

		while (true)
		{
			cout << endl;
			int opcija;
			cout << "Unesite broj stavke: ";
			cin >> opcija;

			switch (opcija)
			{

			case 1:
				cout << "Unesite element koji zelite da ubacite u hip: ";
				stp = 0;
				cin >> elem;
				h.add(elem, stp);
				//cout << endl << "Hip sa umetnutim elementom izgleda ovako: " << endl << h << endl;
				cout << "Broj koraka je " << stp << endl;
				break;

			case 2:
				cout << "Najmanji element u hipu je " << h.get() << endl;
				break;

			case 3:
				stepic = 0;
				h.deletee(stepic);
				cout << "Broj koraka kod brisanja je " << stepic << endl;
				//cout << h << endl;

			case 4:
				cout << "Unesi novi red m-arnog hipa: ";
				cin >> new_m;
				cout << endl;
				//;
				h = h.convertTo(new_m);
				cout << h << endl;
				break;

			case 5:
				//cout << h2 << endl;
				s = 0;
				h = h.unionn(h2, s);
				cout << h << endl;
				cout << "Broj koraka je " << s;
				break;

			case 6:
				cout << h << endl;
				break;

			case 7:
				cout << "Hip je obrisan!" << endl;
				break;

			case 8:
				cout << "Unesite element koji zelite da obrisete: ";
				cin >> e;
				h.delete_any_elem(e);
				cout << endl << h << endl;

			case 9:
				exit(1);
				break;

			default:
				cout << "Izabrali ste pogresan broj stavke, unesite ponovo" << endl;
				break;
			}
		}
	}
	else if (nesto == 2) {		
		cout << "Unesi m: ";
		int M;
		cin >> M;
		
		
		Red r(150, M, "test10.txt");

		cout << endl << "Red je napravljen!";
		cout << endl << endl;
		cout << "1. Provera da li je red prazan" << endl;
		cout << "2. Dohvatanje prvog elementa reda" << endl;
		cout << "3. Brisanje prvog elementa reda" << endl;
		cout << "4. Umetanje elementa u red" << endl;
		cout << "5. Kraj programa" << endl << endl;

		int nes, iii;

		while (true)
		{
			cout << "Izaberite jednu od stavki: ";
			cin >> nes;

			switch (nes)
			{
			case 1:
				if (r.is_empty() == true) {
					cout << "Red je prazan" << endl;
				}
				else
				{
					cout << "Red nije prazan!" << endl;
				}
				break;

			case 2:
				//int br = r.dohvati_prvi_elem();
				cout << "Prvi element reda je ";
				r.dohvati_prvi_elem();
				cout << endl;
				break;

			case 3:
				r.remove();
				cout << "Najmanji element reda ";
				r.dohvati_prvi_elem();
				cout<< " je obrisan!" << endl;
				break;

			case 4:
				cout << "Unesite element koji hocete da ubacite u red: ";
				cin >> iii;
				r = r.insert(iii);
				cout << endl << "Element " << iii << " je ubacen u red!" << endl;
				break;

			case 5:
				exit(1);
				break;

			default:
				cout << "Uneli ste pogresan broj stavke, unesite ponovo" << endl;
				break;
			}
		}

	}
	else
	{
		cout << "Uneli ste pogresan broj!" << endl;
	}

	return 0;
}