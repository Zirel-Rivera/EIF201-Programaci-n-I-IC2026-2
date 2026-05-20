#include "AnalisisAves.h"
#include <iostream>

namespace EIF201 {
	void AnalisisAves::imprimirInversoAux(NodoAve* cab) const
	{
		if (cab == nullptr)
			return;

		imprimirInverso(cab->siguiente);

		std::cout << cab->anillo << " "
			<< cab->especie << " "
			<< cab->peso << " "
			<< cab->sexo << " "
			<< cab->fecha << "\n ";
	}
	NodoAve* AnalisisAves::maxAux(NodoAve* cab, NodoAve* mejor) const
	{
		if (cab == nullptr)
			return mejor;

		if (cab->peso > mejor->peso)
			return nullptr;
	}
	int AnalisisAves::contar(NodoAve* cab) const
	{
		if (cab == nullptr) {
			return;
		}
		return 1 + contar(cab->siguiente);
	}

	double AnalisisAves::sumaPesos(NodoAve* cab) const
	{
		if (cab == nullptr) {
			return 0.0;
		}
		return cab->peso + sumaPesos(cab->siguiente);
	}

	int AnalisisAves::contarEspecie(NodoAve* cab, const std::string& especie) const
	{
		if (cab == nullptr)
			return 0;

		if (cab->especie == especie) {
			return 1 + contarEspecie(cab->siguiente, especie);
		}
		else {
			return contarEspecie(cab->siguiente, especie);
		}
	}

	bool AnalisisAves::existeEspecie(NodoAve* cab, const std::string& especie) const
	{
		if (cab == nullptr)
			return false;
		
		if (cab->especie == especie)
			return true;

		return existeEspecie(cab->siguiente, especie);
	}

	NodoAve* AnalisisAves::aveMasPesada(NodoAve* cab) const
	{
		if (cab == nullptr)
			return nullptr;

		maxAux(cab, cab);

	}

	void AnalisisAves::imprimirCronologico(NodoAve* cab) const
	{
		if (cab == nullptr)
			return;

		std::cout << cab->anillo << " "
			<< cab->especie << " "
			<< cab->peso << " "
			<< cab->sexo << " "
			<< cab->fecha << "\n ";

		imprimirCronologico(cab->siguiente);
			
	}
	void AnalisisAves::imprimirInverso(NodoAve* cab) const
	{
		imprimirInversoAux(cab);
	}

}