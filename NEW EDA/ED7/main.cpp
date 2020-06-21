#include "Arbin.h"
#include <iostream>
#include <string>

using namespace std;

/**
  COMPLEJIDAD: Explica aquí justificadamente cuál es la complejidad de 
               esta función
			   ***A COMPLETAR***

			   Observando la implementación de Arbin.h vemos que la operaciones EsVacio(), HijoDer() e HijoIz() tienen complejidad constante y
			   dado que nuestro arbol tiene n nodos y nuestro algoritmo recorre todos los nodos del arbol una sola vez, podemos concluir que la complejidad de nuestro algoritmo es O(n) y por lo tanto lineal.
*/
void aux_numero_hojas_mas_profundas_que(const Arbin<int>& a, unsigned int k, int &profundidad, int &hojas) {

	if (!a.esVacio()) {
		if (a.hijoDer().esVacio() && a.hijoIz().esVacio() && profundidad > k) {
			hojas++;
		}
		else {
			profundidad++;
			aux_numero_hojas_mas_profundas_que(a.hijoDer(), k, profundidad, hojas);
			aux_numero_hojas_mas_profundas_que(a.hijoIz(), k, profundidad, hojas);
			profundidad--;
		}
	}
}


unsigned int numero_hojas_mas_profundas_que(const Arbin<int>& a, unsigned int k) {
	// A IMPLEMENTAR
	int profundidad = 1;
	int hojas = 0;

	aux_numero_hojas_mas_profundas_que(a,k, profundidad, hojas);

	return hojas;
}


Arbin<int> lee_arbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
  		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = lee_arbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = lee_arbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}



/**
La entrada al programa consiste de líneas formadas por:
(1) Un árbol de enteros
(2) El valor de k
Los árboles se codifican de acuerdo con las siguientes reglas:
(1) El árbol vacío se codifica como #
(2) Los árboles simples se codifican como [v], con  
    v el valor del nodo
(3) Los árboles complejos se codifican como (IvD),
    con I la codificación del hijo izquierdo,
	v el valor de la raíz, y D la codificación
	del hijo derecho.
Para cada línea leida, escribe en la salida estádar
el número de hojas que están a profundidad mayor que k

	
Ejemplo de entrada:

([2]1([4]3[5])) 0
([2]1([4]3[5])) 1
([2]1([4]3[5])) 2
([2]1([4]3[5])) 3
([2]1([4]3[5])) 4
([2]1([4]3[5])) 100

Salida asociada:

3
3
2
0
0
0

*/


int main() {
	Arbin<int> arbol;
	while (cin.peek() != EOF)  {
		Arbin<int> a = lee_arbol(cin);
		int k;
		cin >> k;
		cout << numero_hojas_mas_profundas_que(a,k) << endl;
		string resto_linea;
		getline(cin, resto_linea);
	}
	return 0;
}
