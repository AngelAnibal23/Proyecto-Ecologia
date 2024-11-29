#include "gestorReciclaje.h"
#include <algorithm>
using namespace std; 

GestorReciclaje::~GestorReciclaje() {
    for (Material* material : materiales) {
        delete material;
    }
}

Material* GestorReciclaje::buscarMaterial(const std::string& nombre) {
    for (Material* material : materiales) {
        if (material->getNombre() == nombre) {
            return material; 
        }
    }
    return nullptr; 
}

void GestorReciclaje::agregarMaterial(Material* material) {
    Material* existente = buscarMaterial(material->getNombre());
    if (existente) {
        existente->sumarPeso(material->getKg());
        delete material; 
    } else {
        materiales.push_back(material); 
    }
}

void GestorReciclaje::mostrarMateriales() {
    for (Material* material : materiales) {
        material->mostrarInfo();
    }
}

void GestorReciclaje::ordenarPorKg() {
    std::sort(materiales.begin(), materiales.end(), [](Material* a, Material* b) {
        return a->getKg() > b->getKg();
    });
}

const vector<Material*>& GestorReciclaje::obtenerMateriales() const {
    return materiales;
}