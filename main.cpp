#include "gestorReciclaje.h"
#include <iostream>
#include "funciones.cpp"
#include "funciones.h"
#include <vector>
#include <string>

using namespace std;

void mostrarMenu() {
    cout << "Gestor de Reciclaje\n";
    cout << "1. Agregar material\n";
    cout << "2. Mostrar materiales\n";
    cout << "3. Ordenar materiales por peso\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    GestorReciclaje gestor;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                
                menuMateriales(); 
                
            }
            case 2:
                gestor.mostrarMateriales();
                break;
            case 3:
                gestor.ordenarPorKg();
                cout << "Materiales ordenados por peso.\n";
                break;
            case 4:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
        }
    } while (opcion != 4);

    return 0;
}
