#include <iostream>
#include <string>
#include "cola.h"
#include "pila.h"
using namespace std;



bool esEquilibrada(const string& cadena) {
    // A IMPLEMENTAR
    bool equilibrada = true;
	int colal = 0;
	int pilal = 0;
	
	Cola<char> cola = Cola<char>();
	Pila<char> pila = Pila<char>();
	for (int i = 0; i < cadena.length(); i++) {
		if (cadena[i] == '[' || cadena[i] == '(' || cadena[i] == '{') {
			pila.apila(cadena[i]);
			pilal++;
		}
		else if (cadena[i] == ']' || cadena[i] == ')' || cadena[i] == '}') {
			cola.pon(cadena[i]);
			colal++;
		}
		if (colal == pilal && colal > 0) {
			int i = 0;
			while (i < colal && equilibrada) {
				if (pila.cima() == '(') {
					if (cola.primero() != ')')
						equilibrada = false;
				}
				if (pila.cima() == '{') {
					if (cola.primero() != '}')
						equilibrada = false;
				}
				if (pila.cima() == '[') {
					if (cola.primero() != ']')
						equilibrada = false;
				}
				cola.quita();
				pila.desapila();
				colal--;
				pilal--;
				i++;
			}
		}
	
	}
	if (colal != pilal)
		equilibrada = false;
	
	return equilibrada;
}


int main() {
    string cadena;
    while (getline(cin, cadena)) {
        if (esEquilibrada(cadena))
            cout << "EQUILIBRADA" << endl;
        else
            cout << "NO_EQUILIBRADA" << endl;
    }
    return 0;
}
