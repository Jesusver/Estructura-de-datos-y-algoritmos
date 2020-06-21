#include "Racional.h"
#include <cmath>

//Metodos publicos

Racional::Racional() {
	_numer = new long;
	_denom = new long;
	*_numer = 0;
	*_denom = 1;
}

Racional::Racional(long n, long d) {
	if (d == 0) throw EDenominadorCero();
	_numer = new long;
	_denom = new long;
	*_numer = n;
	*_denom = d;
	Racional::reduce();
}

Racional::Racional(const Racional &r) {
	_numer = new long;
	_denom = new long;
	*_numer = *r._numer;
	*_denom = *r._denom;
}

Racional::~Racional() { delete _numer; delete _denom; }

bool Racional::operator==(const Racional& r) {
	if (*_numer == *r._numer && *_denom == *r._denom) return true;
	else return false;

}

Racional Racional::suma(const Racional &r) {
	long _mcm = Racional::mcm(*_denom, *r._denom);
	long term1 = (*_numer * _mcm) / *_denom;
	long term2 = (*r._numer * _mcm) / *r._denom;
	Racional resul = Racional((term1 + term2), _mcm);
	return resul;

}
Racional Racional::operator-(const Racional& r) {
	long _mcm = Racional::mcm(*_denom, *r._denom);
	long term1 = (*_numer * _mcm) / *_denom;
	long term2 = (*r._numer * _mcm) / *r._denom;
	return Racional((term1 - term2), _mcm);

}

void Racional::operator*=(const Racional& r) {
	*_numer = *_numer * *r._numer;
	*_denom = *_denom * *r._denom;
	Racional::reduce();
}

void Racional::divideYActualiza(const Racional& r) {
	if (*r._numer == 0 && *r._denom == 1) throw EDivisionPorCero();
	*_numer = *_numer * *r._denom;
	*_denom = *_denom * *r._numer;
	Racional::reduce();
}



//**** COMPLETAR
//  Deben implementarse los metodos publicos de la clase
//****


// Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << *f._numer << "/" << *f._denom;
	return out;
}

// Metodos privados
void Racional::reduce() {
	// Se asegura que el denominador siempre sea positivo   
	if (*_denom < 0) {
		*_numer = -(*_numer);
		*_denom = -(*_denom);
	}
	// Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(*_numer, *_denom);
	*_numer /= fsimp;
	*_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	// El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1);
	v2 = abs(v2);
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1 % v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1 * v2 / mcd(v1, v2);
}
