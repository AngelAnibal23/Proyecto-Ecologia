#include "gestorReciclaje.h"
#include "claseMaterial.h"
#include <iostream>
#include <map> 
#include <cstdlib> 

using namespace std; 

void mostrarMenu() {
	system("cls");
	cout <<endl;
    cout << "Gestor de Reciclaje. \n";
    cout << "1. Agregar material. \n";
    cout << "2. Mostrar materiales. \n";
    cout << "3. Ordenar materiales por peso. \n";
    cout << "4. Buscar material especifico. \n";
    cout << "5. Calcular las estadisticas. \n";
    cout << "6. Salir del gestionador de reciclaje. \n"; 
    cout << "Seleccione una opcion: ";
    cout <<endl;
}

void menuMateriales(GestorReciclaje& gestor) {
    int opc;
    float kg;
	system("cls");
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
            cout <<endl;
            break;
        case 2:
            cout << "Ingrese el peso del carton: ";
            cin >> kg;
            gestor.agregarMaterial(new Carton(kg));
            cout <<endl;
            break;
        case 3:
            cout << "Ingrese el peso del vidrio: ";
            cin >> kg;
            gestor.agregarMaterial(new Vidrio(kg));
            cout <<endl;
            break;
        case 4:
            cout << "Ingrese el peso del plastico: ";
            cin >> kg;
            gestor.agregarMaterial(new Plastico(kg));
            cout <<endl;
			break;
        case 5:
            cout << "Ingrese el peso del metal: ";
            cin >> kg;
            gestor.agregarMaterial(new Metal(kg));
            cout <<endl;
			break;
        default:
            cout << "Opcion no valida.\n";
            cout <<endl;
			break;
    }
}

void buscarMaterial(GestorReciclaje& gestor) {
    string nombre;
    cout << "Ingrese el nombre del material que desea buscar (Papel, Carton, Vidrio, Plastico, Metal): ";
    cin >> nombre;

    bool encontrado = false;

    for (Material* material : gestor.obtenerMateriales()) {
        if (material->getNombre() == nombre) {
            material->mostrarInfo();
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "El material '" << nombre << "' no se encuentra en la lista.\n";
    }
}

void calcularEstadisticas(GestorReciclaje& gestor) {
    float pesoTotal = 0;
    map<string, float> pesosPorTipo;

    for (Material* material : gestor.obtenerMateriales()) {
        pesoTotal += material->getKg();
        pesosPorTipo[material->getNombre()] += material->getKg();
    }

    if (pesoTotal == 0) {
        cout << "No hay materiales registrados para calcular estadísticas.\n";
        return;
    }

    cout << "Estadísticas de reciclaje:\n";
    cout << "Peso total reciclado: " << pesoTotal << " kg\n";
    for (const auto& par : pesosPorTipo) {
        float porcentaje = (par.second / pesoTotal) * 100;
        cout << "Material: " << par.first << ", Peso: " << par.second 
             << " kg (" << porcentaje << "%)\n";
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
                buscarMaterial(gestor);
            	break;
            case 5:
            	calcularEstadisticas(gestor);
            	break;
            case 6:
            	cout << "Saliendo del programa...\n";
        		break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    } while (opcion != 4);

    return 0;
}
