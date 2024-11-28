#include "gestorReciclaje.h"
#include "claseMaterial.h"
#include <iostream>
using namespace std; 

void mostrarMenu() {
    cout << "Gestor de Reciclaje\n";
    cout << "1. Agregar material\n";
    cout << "2. Mostrar materiales\n";
    cout << "3. Ordenar materiales por peso\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";
}

void menuMateriales(GestorReciclaje& gestor) {
    int opc;
    float kg;

    cout << "\n_________________MENU MATERIALES_________________" << endl;
    cout << "1.- Papel.\n";
    cout << "2.- Carton.\n";
    cout << "3.- Vidrio.\n";
    cout << "4.- Plastico.\n";
    cout << "5.- Metales.\n";
    cout << "Ingrese una opcion: ";
    cin >> opc;

    switch (opc) {
        case 1:
            cout << "Ingrese el peso del papel: ";
            cin >> kg;
            gestor.agregarMaterial(new Papel(kg));
            break;
        case 2:
            cout << "Ingrese el peso del carton: ";
            cin >> kg;
            gestor.agregarMaterial(new Carton(kg));
            break;
        case 3:
            cout << "Ingrese el peso del vidrio: ";
            cin >> kg;
            gestor.agregarMaterial(new Vidrio(kg));
            break;
        case 4:
            cout << "Ingrese el peso del plastico: ";
            cin >> kg;
            gestor.agregarMaterial(new Plastico(kg));
            break;
        case 5:
            cout << "Ingrese el peso del metal: ";
            cin >> kg;
            gestor.agregarMaterial(new Metal(kg));
            break;
        default:
            cout << "Opcion no valida.\n";
            break;
    }
}

int main() {
    GestorReciclaje gestor;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                menuMateriales(gestor);
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
