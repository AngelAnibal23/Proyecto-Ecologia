#include "gestorReciclaje.h"
#include <iostream>

using namespace std;

void mostrarMenu() {
    cout << "Gestor de Reciclaje\n";
    cout << "1. Agregar material\n";
    cout << "2. Mostrar materiales\n";
    cout << "3. Ordenar materiales por peso\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    GestorReciclaje gestor;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                float kg;
                cout << "Ingrese el peso del papel: ";
                cin >> kg;
                gestor.agregarMaterial(new Papel(kg));
                break;
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
                cout << "Opción no válida.\n";
                break;
        }
    } while (opcion != 4);

    return 0;
}
