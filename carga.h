#pragma once
#include <iostream>
#include <string>

using namespace std;

class Carga {
protected:
    string nombre;
    float potencia;
    bool estado;

public:
    Carga(string n, float p) : nombre(n), potencia(p), estado(true) {}
    virtual ~Carga() {}

    string getNombre() { return nombre; }
    float getPotencia() { return potencia; }
    bool getEstado() { return estado; }

    virtual void setEstado(bool e) { estado = e; }
    virtual void mostrarInfo() = 0; // Método virtual puro
};