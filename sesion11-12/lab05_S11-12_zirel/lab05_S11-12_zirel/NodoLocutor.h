#ifndef  NODO_LOCUTOR_H
#define NODO_LOCUTOR_H 

#include <iostream>
#include <string>
using namespace std;

namespace EIF201 {

	struct  NodoLocutor
	{
		string nombre;
		NodoLocutor* siguiente;
		int turnosAsignados;

		NodoLocutor(const string& n)
			: nombre(n), siguiente(nullptr), turnosAsignados(0) {
			cout << "[NodoLocutor creado: " << n << "]" << endl;
		}
		~NodoLocutor() {
			cout << "[NodoLocutor destruido: " << nombre << "]" << endl;
		}

	};

}
#endif // ! NODO_LOCUTOR_H