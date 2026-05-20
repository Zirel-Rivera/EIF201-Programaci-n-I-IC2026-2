#include "Bitacora.h"
#include <fstream>
#include "NodoAve.h"
#include<iostream>
#include<string>

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

		while ();
		return 0;
	}

}
