#ifndef  HistorialDoble_H
#define HistorialDoble_H

#include "NodoHistorial.h"

namespace EIF201 {

	class HistorialDoble
	{
	private:
		NodoHistorial* cabeza;
		NodoHistorial* cola;
		int cantidad;

	public:

		HistorialDoble();
		~HistorialDoble();

		void insertarAlinicio(const string& cancion);
		void insertarAlfinal(const string& cancion);
		void insertarEnPosicion(const string& cancion, int pos);
		bool insertarAntesDe(const string& referencia, const string& nueva);
		bool insertarDespuesDe(const string& referencia, const string& nueva);
		bool existeCancion(const string& cancion) const;
		int obtenerPosicion(const string&cancion) const;
		string obtenerEnPosicion(int pos) const;
		int obtenerPosicionDesdeElFinal(const string& cancion) const;
		bool eliminarPrimera(const string& cancion);
		bool eliminarUltima(const string& cancion);
		bool eliminarEnPosicion(int pos);
		bool eliminarCabeza();
		bool eliminarCola();

		void imprimirCronologico() const;
		void imprimirInverso() const;

		int getCantidad() const;
		bool estaVcia() const;
	};


}

#endif // ! HistorialDoble_H
