#ifndef GESTOR_RECICLAJE_H
#define GESTOR_RECICLAJE_H

#include <vector>
#include <string>

using namespace std; 

class GestorReciclaje {
protected:
    vector<Material*> materiales;

public:
    ~GestorReciclaje();
    void agregarMaterial(Material* material);
    void mostrarMateriales();
    void ordenarPorKg();
};

#endif
