#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <string>

using namespace std;

class Material {
protected:
    string nombre;
    float kg;

public:
    Material(string nombre, float kg);
    virtual void mostrarInfo() = 0;
    float getKg();
    string getNombre();
};

class Papel : public Material {
public:
    Papel(float kg);
    void mostrarInfo() override;
};

#endif
