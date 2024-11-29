#include "gestorReciclaje.h"
#include <algorithm>
#include <iomanip>
#include <cstdlib> 

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

void GestorReciclaje::establecerMeta(float meta) {
    if (meta > 0) {
        metaReciclaje = meta;
        cout << "Meta de reciclaje establecida en: " << metaReciclaje << " kg.\n";
    } else {
        cout << "La meta debe ser un valor positivo.\n";
    }
}

float GestorReciclaje::calcularPesoTotal() {
    float total = 0;
    for (Material* m : materiales) {
        total += m->getKg();
    }
    return total;
}

void GestorReciclaje::verificarProgreso() {
    float totalReciclado = calcularPesoTotal();
    cout << fixed << setprecision(2);
    cout << "Progreso actual: " << totalReciclado << " kg de " << metaReciclaje << " kg.\n";
    if (totalReciclado == metaReciclaje) {
        cout << "¡Felicidades! Has logrado tu meta!.\n";
        
	}
    else if(totalReciclado > metaReciclaje){
    	cout << "!Asombroso! Has superado la meta establecida!. \n"; 
	   
    } else {
        float restante = metaReciclaje - totalReciclado;
        cout << "Te faltan " << restante << " kg para alcanzar la meta.\n";
    }
}