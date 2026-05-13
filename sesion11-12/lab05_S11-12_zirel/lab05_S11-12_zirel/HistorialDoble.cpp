#include "HistorialDoble.h"

namespace EIF201 {
	
	HistorialDoble::HistorialDoble()
		: cabeza(nullptr), cola(nullptr), cantidad(0){}

	HistorialDoble::~HistorialDoble() {
		NodoHistorial* actual = cabeza;
		while (actual != nullptr) {
			NodoHistorial* temp = actual->siguiente;
			delete actual;
			actual = temp;
		}
		cabeza = nullptr;
		cola = nullptr;
		cout << "[HistorialDoble destruido]" << endl;
	}
	
	void HistorialDoble::insertarAlinicio(const string& cancion) {
		NodoHistorial* nuevo = new NodoHistorial(cancion);
		if (cabeza == nullptr) {
			cabeza = nuevo;
			cola = nuevo;
		}
		else {
			nuevo->siguiente = cabeza;
			cabeza->anterior = nuevo;
			cabeza = nuevo;
		}
		cantidad++;
	}

	void HistorialDoble::insertarAlfinal(const string& cancion) {
		NodoHistorial* nuevo = new NodoHistorial(cancion);
		if (cola == nullptr) {
			cabeza = nuevo;
			cola = nuevo;

		}
		cantidad++;
	}

	void HistorialDoble::insertarEnPosicion(const string& cancion, int pos)
	{
		if (pos <= 0) { insertarAlinicio(cancion); return; }
		if (pos >= 0) { insertarAlfinal(cancion); return; }

		NodoHistorial* nuevo = new NodoHistorial(cancion);
		NodoHistorial* actual = cabeza;
		for (int i = 0; i < pos; i++) {
			actual = actual->siguiente;
		}

		NodoHistorial* previo = actual->anterior;
		nuevo->siguiente = actual;
		nuevo->anterior = previo;
		previo->siguiente = nuevo;
		actual->anterior = nuevo;
		cantidad++;

	}

	bool HistorialDoble::insertarAntesDe(const string& referencia, const string& nueva) {
		NodoHistorial* actual = cabeza;
		while (actual != nullptr) {
			if (actual->cancion == referencia) {
				if (actual == cabeza) {
					insertarAlinicio(nueva);
				}
				else {
					NodoHistorial* nuevo = new NodoHistorial(nueva);
					NodoHistorial* previo = actual->anterior;
					nuevo->siguiente = actual;
					nuevo->anterior = actual;
					previo->siguiente = nuevo;
					actual->siguiente = nuevo;
					cantidad++;
				}
				return true;
			}
			actual = actual->siguiente;
		}
		return false;
	}

	bool HistorialDoble::insertarDespuesDe(const string& referencia, const string& nueva)
	{
		NodoHistorial* actual = cabeza;
		while (actual != nullptr) {
			if (actual->cancion == referencia) {
				if (actual == cola) {
					insertarAlfinal(nueva);
				}
				else {
					NodoHistorial* nuevo = new NodoHistorial(nueva);
					NodoHistorial* sig = actual->siguiente;
					nuevo->anterior = actual;
					nuevo->siguiente = sig;
					actual->siguiente = nuevo;
					sig->anterior = nuevo;
					cantidad++;
				}
				return true;
			}
			actual = actual->siguiente;
		}
		return false;
	
	}

	bool HistorialDoble::existeCancion(const string& cancion) const {
		NodoHistorial* actual = cabeza;
		while (actual != nullptr) {
			if (actual->cancion == cancion) {
				return true;
			}
			actual = actual->siguiente;
		}
		return false;
	}
	
	int HistorialDoble::obtenerPosicion(const string& cancion) const {
		NodoHistorial* actual = cabeza;
		int pos = 0;
		while (actual != nullptr) {
			if (actual->cancion == cancion) {
				return pos;
			}
			actual = actual->siguiente;
			pos++;
		}
		return -1;
	}

	string HistorialDoble::obtenerEnPosicion(int pos) const {
		if (pos < 0 || pos >= cantidad) {
			return "";
		}
		NodoHistorial* actual = cabeza;
		for (int i = 0; i < pos; i++) {
			actual = actual->siguiente;
		}
		return actual->cancion;
	}

	int HistorialDoble::obtenerPosicionDesdeElFinal(const string& cancion) const {
		NodoHistorial* actual = cola;
		int pos = 0;
		while (actual != nullptr) {
			if (actual->cancion == cancion) {
				return pos;
			}
			actual = actual->anterior;
			pos++;
		}
		return -1;
	}

	bool HistorialDoble::eliminarPrimera(const string& cancion) {
		NodoHistorial* actual = cabeza;
		while (actual != nullptr) {
			if (actual->cancion == cancion) {
				if (actual->anterior != nullptr) {
					actual->anterior->siguiente = actual->siguiente;
				}
				else {
					cabeza = actual->siguiente;
				}
				if (actual->siguiente != nullptr) {
					actual->siguiente->anterior = actual->anterior;
				}
				else {
					cola = actual->anterior;
				}
				delete actual;
				actual = nullptr;
				cantidad--;
				return true;
			}
			actual = actual->siguiente;
		}
		return false;
	}

	bool HistorialDoble::eliminarUltima(const string& cancion) {
		NodoHistorial* actual = cola;
		while (actual != nullptr) {
			if (actual->cancion == cancion) {
				if (actual->anterior != nullptr) {
					actual->anterior->siguiente = actual->siguiente;
				}
				else {
					cabeza = actual->siguiente;
				}
				if (actual->siguiente != nullptr) {
					actual->siguiente->anterior = actual->anterior;
				}
				else {
					cola = actual->anterior;
				}
				delete actual;
				actual = nullptr;
				cantidad--;
				return true;
			}
			actual = actual->anterior;
		}
		return false;
	}

	bool HistorialDoble::eliminarEnPosicion(int pos) {
		if (pos < 0 || pos >= cantidad) {
			return false;
		}
		if (pos == 0) {
			return eliminarCabeza();
		}
		if (pos == cantidad - 1) {
			return eliminarCola();
		}
		NodoHistorial* actual = cabeza;
		for (int i = 0; i < pos; i++) {
			actual = actual->siguiente;
		}
		actual->anterior->siguiente = actual->siguiente;
		actual->siguiente->anterior = actual->anterior;
		delete actual;
		actual = nullptr;
		cantidad--;
		return true;
	}

	bool HistorialDoble::eliminarCabeza() {
		if (cabeza == nullptr) { return false; }
		return eliminarPrimera(cabeza->cancion);
	}

	bool HistorialDoble::eliminarCola() {
		if (cola == nullptr) { return false; }
		return eliminarPrimera(cola->cancion);
	}

	void HistorialDoble::imprimirCronologico() const {
		NodoHistorial* actual = cabeza;
		cout << "Cronológico: ";
		while (actual != nullptr) {
			cout << actual->cancion;
			if (actual->siguiente != nullptr) { cout << " <-> "; }
			actual = actual->siguiente;
		}
		cout << endl;
	}

	void HistorialDoble::imprimirInverso() const {
		NodoHistorial* actual = cola;
		cout << "Inverso: ";
		while (actual != nullptr) {
			cout << actual->cancion;
			if (actual->anterior != nullptr) { cout << " <-> "; }
			actual = actual->anterior;
		}
		cout << endl;
	}

	int HistorialDoble::getCantidad() const { return cantidad; }

	bool HistorialDoble::estaVcia() const { return cabeza == nullptr; }


}
