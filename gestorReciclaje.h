#ifndef GESTOR_RECICLAJE_H
#define GESTOR_RECICLAJE_H

#include <vector>
#include "claseMaterial.h"
using namespace std; 

class GestorReciclaje {
private:
    vector<Material*> materiales;
    float metaReciclaje; 
    Material* buscarMaterial(const string& nombre);
    
public:
    ~GestorReciclaje();
    const vector<Material*>& obtenerMateriales() const; 
    void agregarMaterial(Material* material);
    void mostrarMateriales();
    void ordenarPorKg();
    void establecerMeta(float meta); // Nueva función para establecer meta
    void verificarProgreso(); // Nueva función para verificar progreso
    float calcularPesoTotal(); // Función auxiliar para el peso total
};

#endif