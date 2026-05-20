#include <iostream>
#include "Bitacora.h"
#include "AnalisisAves.h"

using namespace std;
using namespace EIF201;

int main() {
    Bitacora bitacora("datos/anillamientos.txt");
    AnalisisAves analisis;
    NodoAve* lista = nullptr;

    int opcion;

    do {
        cout << "     Refugio de aves       \n";
        cout << "  1. Registrar ave\n";
        cout << "  2. Cargar todas las aves\n";
        cout << "  3. Cargar aves validas\n";
        cout << "  4. Contar aves en memoria\n";
        cout << "  5. Suma de pesos\n";
        cout << "  6. Contar por especie\n";
        cout << "  7. Existe especie\n";
        cout << "  8. Ave mas pesada\n";
        cout << "  9. Imprimir cronologico\n";
        cout << " 10. Imprimir inverso\n";
        cout << " 11. Liberar lista\n";
        cout << "  0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1: {
            string anillo, especie, fecha;
            double peso;
            char sexo;
            cout << "Anillo: "; cin >> anillo;
            cout << "Especie: "; cin.ignore(); getline(cin, especie);
            cout << "Peso (g): "; cin >> peso;
            cout << "Sexo: "; cin >> sexo;
            cout << "Fecha (DD-MM-AAAA): "; cin >> fecha;
            if (bitacora.registrarAve(anillo, especie, peso, sexo, fecha))
                cout << "Ave registrada correctamente.\n";
            else
                cout << "Error al registrar.\n";
            break;
        }

        case 2: {
            Bitacora::liberarLista(lista);
            int n = bitacora.cargarTodas(lista);
            cout << "Aves cargadas: " << n << "\n";
            break;
        }

        case 3: {
            Bitacora::liberarLista(lista);
            int n = bitacora.cargarValidas(lista);
            cout << "Validas: " << bitacora.getValidas()
                << " | Descartadas: " << bitacora.getDescartadas() << "\n";
            break;
        }

        case 4: {
            cout << "Total aves en memoria: " << analisis.contar(lista) << "\n";
            break;
        }

        case 5: {
            cout << "Suma de pesos: " << analisis.sumaPesos(lista) << "g\n";
            break;
        }

        case 6: {
            string especie;
            cin.ignore();
            cout << "Especie a buscar: "; getline(cin, especie);
            cout << "Cantidad: " << analisis.contarEspecie(lista, especie) << "\n";
            break;
        }

        case 7: {
            string especie;
            cin.ignore();
            cout << "Especie a buscar: "; getline(cin, especie);
            cout << (analisis.existeEspecie(lista, especie) ? "Si existe.\n" : "No existe.\n");
            break;
        }

        case 8: {
            NodoAve* pesada = analisis.aveMasPesada(lista);
            if (pesada != nullptr)
                cout << "Ave mas pesada: " << pesada->especie
                << " | " << pesada->anillo
                << " | " << pesada->peso << "g\n";
            else
                cout << "Lista vacia.\n";
            break;
        }

        case 9: {
            cout << "\n-- Cronologico --\n";
            analisis.imprimirCronologico(lista);
            break;
        }

        case 10: {
            cout << "\n-- Inverso --\n";
            analisis.imprimirInverso(lista);
            break;
        }

        case 11: {
            Bitacora::liberarLista(lista);
            cout << "Lista liberada.\n";
            break;
        }

        case 0:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);

    Bitacora::liberarLista(lista);
    return 0;
}