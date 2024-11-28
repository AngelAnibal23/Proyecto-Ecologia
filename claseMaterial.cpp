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

Vidrio::Vidrio(float kg) : Material("Vidrio", kg) {} 

void Vidrio::mostrarInfo(){
    cout<< "Material: " << nombre << ", Peso: " << kg << "kg" <<endl; 
}

Carton::Carton(float kg) : Material("Carton", kg) {} 

void Carton::mostrarInfo(){
    cout<< "Material: " << nombre << ", Peso: " << kg << "kg" <<endl; 
}

Plastico::Plastico(float kg) : Material("Plastico", kg) {} 

void Plastico::mostrarInfo(){
    cout<< "Material: " << nombre << ", Peso: " << kg << "kg" <<endl; 
}

Metal::Metal(float kg) : Material("Metal", kg) {} 

void Metal::mostrarInfo(){
    cout<< "Material: " << nombre << ", Peso: " << kg << "kg" <<endl; 
}