#include <iostream>
#include <fstream>
#include <string>
#include "Arbin.h"

using namespace std;

void aux(const Arbin<char>& falda, int &resul, int &segmentos) {
	if (!falda.esVacio()) {
		if (falda.raiz() == 'X') {
			resul += segmentos * 2;
		}
		segmentos++;
		if (!falda.hijoDer().esVacio()) {
			aux(falda.hijoDer(),resul,segmentos);
		}
		if (!falda.hijoIz().esVacio()) {
			aux(falda.hijoIz(), resul, segmentos);
		}
		segmentos--;
	}
	
}


int tiempoAyuda(const Arbin<char>& falda) {
	// A IMPLEMENTAR
	int resul = 0;
	int segmentos = 0;
	aux(falda, resul, segmentos);
	return resul;
}

Arbin<char> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<char>();
	case '[': {
		char raiz;
		in >> raiz;
  		in >> c;
		return Arbin<char>(raiz);
	}
	case '(': {
		Arbin<char> iz = leeArbol(in);
		char raiz;
		in >> raiz;
		Arbin<char> dr = leeArbol(in);
		in >> c;
		return Arbin<char>(iz, raiz, dr);
	}
	default: return Arbin<char>();
	}
}

int main() {
	Arbin<char> falda;
	while (cin.peek() != EOF)  {
		cout << tiempoAyuda(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}