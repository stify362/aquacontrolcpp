#pragma once
#include "Carga.h"

class CargaAplazable : public Carga {
public:
    CargaAplazable(string n, float p) : Carga(n, p) {}

    void mostrarInfo() override {
        cout << "[Aplazable] " << nombre << " | " << potencia << " kW | Estado: " << (estado ? "ENCENDIDA" : "APAGADA") << endl;
    }
};