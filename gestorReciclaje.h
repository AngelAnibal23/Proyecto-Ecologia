#ifndef GESTOR_RECICLAJE_H
#define GESTOR_RECICLAJE_H

#include <vector>
#include "claseMaterial.h"
using namespace std; 

class GestorReciclaje {
private:
    vector<Material*> materiales;
    Material* buscarMaterial(const string& nombre);
    
public:
    ~GestorReciclaje();
    const vector<Material*>& obtenerMateriales() const; 
    void agregarMaterial(Material* material);
    void mostrarMateriales();
    void ordenarPorKg();
};

#endif