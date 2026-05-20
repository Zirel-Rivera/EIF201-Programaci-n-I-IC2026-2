#include <iostream>
#include"Bitacora.h"
#include "AnalisisAves.h"


int main()
{
    EIF201::Bitacora Bitacora("datos/anillamientos.txt");


    if (Bitacora.registrarAve("A001", "Garza Tigre", 450.5, 'M', "2024-03-15")) {
        std::cout << "Ave registrada correctamente\n";
    }
    else {
        std::cout << "Error al registrar\n";
    }

}
