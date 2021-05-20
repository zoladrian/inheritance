#include <iostream>
using namespace std;
int const n = 10;
class Wektor
{
	int rozm = 0;
	int pojemnosc = 0;
	int* arr = 0;

public:
	Wektor() {
		arr = new int[6];
		pojemnosc = 6;
		rozm = 0;
	}
	Wektor(int rozmiar) {
		rozmiar = n;
		arr = new int[n];
		pojemnosc = n;
	}
	Wektor(const Wektor& wektor) {
		arr = wektor.arr;
		pojemnosc = wektor.pojemnosc;
		rozm = wektor.rozm;
	}
	~Wektor() {
	};



	int il_skalar(Wektor& a, Wektor& b)
	{
		int wynik = 0;

		for (int i = 0; i <= rozm; i++) {
			wynik += (a[i] * b[i]);
		}
		cout << "Iloczyn skalarny wektorow wynosi " << wynik << endl;
	}
	int liczb_element(Wektor& a)
	{
		cout << "liczba elementow: " << rozm << endl;
	}
	Wektor operator+(const Wektor& a) {
		Wektor ret = a;
		for (int i = 0; i < rozm; i++)
			ret.arr[i] += this->arr[i];

		return ret;
	}
	Wektor operator-(const Wektor& a) {
		Wektor ret = *this;
		for (int i = 0; i < rozm; i++)
			ret.arr[i] -= a.arr[i];

		return ret;
	}
	Wektor operator++(int) {
		for (int i = 0; i < rozm; i++)
			arr[i]++;

		return *this;
	}
	Wektor operator--(int) {
		for (int i = 0; i < rozm; i++)
			arr[i]--;

		return *this;
	}
	int& operator[](int indeks) {
		return arr[indeks];
	}
};
class Macierz : public Wektor {

public:
	int** Macierz1;
	int lkolumn = 0;
	int lwierszy = 0;

	Macierz() {

	}

	Macierz(int lkolumn, int lwierszy) {
#define lkolumn = 4;
#define lwierszy = 4;
	}
	Macierz(const Macierz& wektor) {
		this->lwierszy = wektor.lwierszy;
		this->lkolumn = wektor.lkolumn;
		for (int i = 0; i < lwierszy; i++) {
			for (int j = 0; j < lkolumn; j++) {
				Macierz[i][j] = wektor.Macierz[i][j];
			}


		}
		~Macierz() {}

	};

	int main()
	{
		Macierz a, b, c, d;
		a.add(1, 2, 3, 4);
		b.add(2, 5, 6, 5);
		c.add(3, 5, 4, 3);
		d.add(4, 2, 1, 7);
		Macierz x, y, w, z;
		x.add(2, 5, 6, 1);
		y.add(3, 5, 7, 9);
		w.add(4, 1, 5, 6);
		z.add(5, 5, 3, 1);



		cout << "+dodawanie+" << endl;
		for (int i = 0; i >= 4; i++) {
			cout << a[i] + x[i] << "  " << b[i] + y[i] << "  " << c[i] + w[i] << "  " << d[i] + z[i] << endl;
		}

		cout << endl << "\n-odejmowanie-" << endl;
		for (int i = 0; i <= 4; i++) {
			cout << a[i] - x[i] << "  " << b[i] - y[i] << "  " << c[i] - w[i] << "  " << d[i] - z[i] << endl;
		}
		cout << "inkrementacja++" << endl;
		for (int i = 0; i <= 4; i++) {
			cout << a[i]++ << "  " << b[i]++ << "  " << c[i]++ << d[i]++ << endl;
		}
		cout << "dekrementacja" << endl;
		for (int i = 0; i <= 4; i++) {
			cout << a[i]-- << "  " << b[i]-- << "  " << c[i]-- << "  " << d[i]-- << endl;
		}


		cout << "mnożenie" << endl;

		for (int i = 0; i <= 4; i++) {
			for (int j = 4; j >= 0; j--)
				cout << a[i] * z[j] << "  " << b[i] * w[j] << "  " << c[i] * y[j] << "  " << d[i] * x[j] << endl;

		}

	}
