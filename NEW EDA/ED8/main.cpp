#include <iostream>
#include <string>
#include "lista.h"
#include "diccionario.h"
using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
  public:
    string alumno;
    int nota;	
	Puntuacion(const string& nombre, int puntuacion): alumno(nombre), nota(puntuacion) {}
};


void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	  // A IMPLEMENTAR  
	Diccionario<string, int> aux;
	int lon;
	if (bien.longitud() > mal.longitud()) {
		lon = bien.longitud();
	}
	else {
		lon = mal.longitud();
	}
	int x = 0;
	int y = 0;

	while (x < lon && y < lon) {

		if (x < bien.longitud()) {
			if (aux.contiene(bien.elem(x))){
				aux.busca(bien.elem(x)).setVal(aux.busca(bien.elem(x)).valor() + 1);
			}
			else {
				aux.inserta(bien.elem(x), 1);
			}
			x++;
		}

		if (y < mal.longitud()) {
			if (aux.contiene(mal.elem(y))) {
				aux.busca(mal.elem(y)).setVal(aux.busca(mal.elem(y)).valor() - 1);
			}
			else {
				aux.inserta(mal.elem(y), -1);
			}
			y++;
		}
	}

	Diccionario<string, int>::ConstIterator i = aux.cbegin();
	Diccionario<string, int>::ConstIterator e = aux.cend();

	while (i != e) {
		if(i.valor() != 0)
			listado.pon_ppio(Puntuacion(i.clave(), i.valor()));
		i.next();
	}
}


void imprimePuntuaciones(Lista<Puntuacion>& listado) {
  Lista<Puntuacion>::ConstIterator i = listado.cbegin();
  Lista<Puntuacion>::ConstIterator e = listado.cend();
  while (i != e) {
	  cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
      i.next();	  
  }  
  cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
  string comienzo;
  while (cin >> comienzo) {
	 Lista<string> bien;
	 Lista<string> mal;
	 Lista<Puntuacion> listado;
	 leeResultados(bien, mal);
	 califica(bien, mal,listado);
	 imprimePuntuaciones(listado);
  }
  return 0;   
}