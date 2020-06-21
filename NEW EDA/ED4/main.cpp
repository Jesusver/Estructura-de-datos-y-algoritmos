#include "cola.h"
#include <iostream>
using namespace std;

void metodoaux(int m, Cola<int> &cola, Cola<int> &colaux) {
	int contador = 0;
	int n = cola.longitud();
	while (contador < n) {
		if (contador % m == 0) {
			cola.quita();
		}
		else {
			colaux.pon(cola.primero());
			cola.quita();
		}
		contador++;
	}
	

}
// A IMPLEMENTAR
void supervivientes(int n, Cola<int>& cola) {
	int i = 1;
	while (i<=n) {
		cola.pon(i);
		i++;
	}

	int m = 2;
	Cola<int> colaux = Cola<int>();
	int orden = 0;
	while (m <= cola.longitud() || m<=colaux.longitud()) {
		if (orden % 2 == 0)
			metodoaux(m,cola,colaux);
		else
			metodoaux(m, colaux, cola);
		orden++;
		m++;
	}
	if(orden%2!=0)
		cola = colaux;
}

int main() {
	
	int n;
	Cola<int> cola;

	cin >> n;
	while (n != 0){

		supervivientes(n, cola);

		cout << n << ":";
		while (!cola.esVacia()) {
			cout << " " << cola.primero();
			cola.quita();
		}
		cout << endl;
		
		cin >> n;	
	}
		
	return 0;
}
