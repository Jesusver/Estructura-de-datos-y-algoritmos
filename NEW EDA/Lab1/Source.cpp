#include <iostream>
#include <string>
using namespace std;

const int MAX_HILERA = 300000;
const int MAX_COCHE = 100000;
int v[MAX_HILERA];
int posEscondite(int v[], int n, int k) {
	int ini = k;
	int fin = k;
	int suma = v[k];
	int sumaMAX = 0;
	int posIni=0;
	while (fin < n) {
		if (fin - ini < k-1) {
			fin++;
			suma = suma + v[fin];
		}
		else {
			ini++;
			fin++;
			suma = suma + v[fin];
			suma = suma - v[ini - 1];
			if (suma > sumaMAX) {
				posIni = ini;
				sumaMAX = suma;
			}

		}
	}
	return posIni;
}

void resuelve() {
	int k;
	int hilera;
	

	cin >> hilera;
	cin >> k;
	for (int i = 0; i < hilera; i++) {
		cin >> v[i];
	}
	cout<<posEscondite(v,hilera,k)<<endl;
}

int main() {
	int nCasos;
	cin >> nCasos;

	for (int i = 0; i < nCasos; i++) {
		resuelve();
	}
	return 0;
}