#include "gestorReciclaje.h"
#include <algorithm>
using namespace std; 

GestorReciclaje::~GestorReciclaje() {
    for (Material* material : materiales) {
        delete material;
    }
}

void GestorReciclaje::agregarMaterial(Material* material) {
    materiales.push_back(material);
}

void GestorReciclaje::mostrarMateriales() {
    for (Material* material : materiales) {
        material->mostrarInfo();
    }
}

void GestorReciclaje::ordenarPorKg() {
    sort(materiales.begin(), materiales.end(), [](Material* a, Material* b) {
        return a->getKg() > b->getKg();
    });
}
