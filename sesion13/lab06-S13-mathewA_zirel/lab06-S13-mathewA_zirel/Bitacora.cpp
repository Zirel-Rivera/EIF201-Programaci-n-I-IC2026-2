#include "Bitacora.h"
#include <fstream>
#include "NodoAve.h"
#include<iostream>
#include<string>
#include <sstream>

namespace EIF201 {

	Bitacora::Bitacora(const std::string& ruta)
	{
		this->ruta_ = ruta;
		this->validas_ = 0;
		this->descartadas_ = 0;
	}

	bool Bitacora::registrarAve(const std::string& anillo, const std::string& especie, double peso, char sexo, const std::string& fecha)
	{
		std::ofstream salida(ruta_,std::ios::app);

		if (!salida.is_open()) {
			return false;
		}
		salida << anillo << ";" << especie << ";" << peso << ";" << sexo << ";" << fecha << std::endl;

		return true;
	}

	int Bitacora::cargarTodas(NodoAve*& cabeza)
	{
		std::ifstream salida(ruta_);
		if (!salida.is_open()) {
			cabeza = nullptr;
			return 0;
		}
		cabeza = nullptr;
		std::string linea;
		int cantidad = 0;

		while (getline(salida, linea)) {
			std::stringstream ss(linea);
			std::string anillo;
			std::string especie;
			std::string pesoStr;
			std::string sexoStr;
			std::string fecha;

			getline(ss, anillo, ';');
			getline(ss, especie, ';');
			getline(ss, pesoStr, ';');
			getline(ss, sexoStr, ';');
			getline(ss, fecha, ';');
			NodoAve* nuevo = new NodoAve(anillo, especie, stod(pesoStr), sexoStr[0], fecha);

			if (cabeza == nullptr) {
				cabeza = nuevo;
			}
			else {
				NodoAve* temp = cabeza;
				while (temp->siguiente != nullptr) {
					temp = temp->siguiente;
				}
				temp->siguiente = nuevo;
			}
			cantidad++;
		}

		salida.close();
		return cantidad;
		}

	int Bitacora::cargarValidas(NodoAve*& cabeza)
	{
		std::ifstream salida(ruta_);

		if (!salida.is_open()) {
			cabeza = nullptr;
			return 0;
		}

		cabeza = nullptr;

		std::string linea;
		int validas = 0;

		while (getline(salida, linea)) {

			if (linea.empty()) {
				descartadas_++;
				continue;
			}

			std::stringstream ss(linea);

			std::string anillo;
			std::string especie;
			std::string pesoStr;
			std::string sexoStr;
			std::string fecha;

			bool ok =
				getline(ss, anillo, ';') &&
				getline(ss, especie, ';') &&
				getline(ss, pesoStr, ';') &&
				getline(ss, sexoStr, ';') &&
				getline(ss, fecha, ';');

			if (!ok) {
				descartadas_++;
				continue;
			}

			double peso;

			try {
				peso = stod(pesoStr);
			}
			catch (...) {
				descartadas_++;
				continue;
			}

			if (peso <= 0) {
				descartadas_++;
				continue;
			}

			char sexo = sexoStr[0];

			if (sexo != 'M' && sexo != 'H' && sexo != 'X') {
				descartadas_++;
				continue;
			}

			NodoAve* nuevo = new NodoAve(anillo, especie, peso, sexo, fecha);

			if (cabeza == nullptr) {
				cabeza = nuevo;
			}
			else {

				NodoAve* aux = cabeza;

				while (aux->siguiente != nullptr) {
					aux = aux->siguiente;
				}

				aux->siguiente = nuevo;
			}

			validas++;
			validas_++;
		}

		salida.close();

		return validas;
	
	}

	int Bitacora::getValidas() const
	{
		return validas_;
	}

	int Bitacora::getDescartadas() const
	{
		return descartadas_;
	}

	void Bitacora::liberarLista(NodoAve*& cabeza)
	{
		NodoAve* temp;
		while (cabeza != nullptr) {
			temp = cabeza; 
			cabeza = cabeza->siguiente; 
			delete temp;
		} cabeza = nullptr;
	}

	
	}

