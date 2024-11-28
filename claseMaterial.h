#ifndef MATERIAL_H
#define MATERIAL_H

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

class Vidrio : public Material{
    public: 
        Vidrio(float kg); 
        void mostrarInfo() override; 
}; 

class Metal : public Material{
    public: 
        Metal(float kg); 
        void mostrarInfo() override; 
}; 

class Plastico : public Material{
    public: 
        Plastico(float kg); 
        void mostrarInfo() override; 
};

class Carton : public Material{
    public: 
        Carton(float kg); 
        void mostrarInfo() override; 
}; 

#endif
