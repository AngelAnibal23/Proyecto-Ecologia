#include "claseMaterial.h"
#include <iostream>

using namespace std;

Material::Material(string nombre, float kg) : nombre(nombre), kg(kg) {}

float Material::getKg() { return kg; }
string Material::getNombre() { return nombre; }

Papel::Papel(float kg) : Material("Papel", kg) {}

void Papel::mostrarInfo() {
    cout << "Material: " << nombre << ", Peso: " << kg << " kg" << endl;
}
