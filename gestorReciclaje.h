#ifndef GESTOR_RECICLAJE_H
#define GESTOR_RECICLAJE_H

#include <vector>
#include "claseMaterial.h"

class GestorReciclaje {
private:
    vector<Material*> materiales;

public:
    ~GestorReciclaje();
    void agregarMaterial(Material* material);
    void mostrarMateriales();
    void ordenarPorKg();
};

#endif
