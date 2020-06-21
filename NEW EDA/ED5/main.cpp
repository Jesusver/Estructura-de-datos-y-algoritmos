#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS



void invierteSecuenciasNoVocales(Lista<char> &mensaje) {
	 // A IMPLEMENTAR
	Lista<char> resul = Lista<char>();
	Lista<char> elementos = Lista<char>();
	Lista<char>::ConstIterator it = mensaje.cbegin();
	while (it != mensaje.cend()) {
		if (it.elem() == 'a' || it.elem() == 'e' || it.elem() == 'i' || it.elem() == 'o' || it.elem() == 'u' || it.elem() == 'A' || it.elem() == 'E' || it.elem() == 'I' || it.elem() == 'O' || it.elem() == 'U') {
			int i = 0;
			int lon = elementos.longitud();
			while (i < lon) {
				resul.pon_final(elementos.primero());
				elementos.quita_ppio();
				i++;
			}
			resul.pon_final(it.elem());
		}
		else {
			elementos.pon_ppio(it.elem());
		}
		it.next();
	}
	int i = 0;
	int lon = elementos.longitud();
	while (i < lon) {
		resul.pon_final(elementos.primero());
		elementos.quita_ppio();
		i++;
	}
	mensaje = resul;

}

 
// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	l.print();
	cout << endl;
}


// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();
}

  // Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for(unsigned int i=0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);  
}

int main() {
	string linea;
	while(getline(cin,linea)) {
	   Lista<char> mensaje;
	   construyeMensaje(linea,mensaje);
       codifica(mensaje);
	   imprime(mensaje);
	}
	return 0;
}	
