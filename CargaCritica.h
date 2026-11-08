#pragma once
#include "Carga.h"

class CargaCritica : public Carga {
public:
    CargaCritica(string n, float p) : Carga(n, p) {}

    void setEstado(bool e) override {
        if (!e) {
            cout << "[ALERTA] " << nombre << " es una carga CRITICA y no se puede apagar.\n";
        } else {
            estado = true;
        }
    }

    void mostrarInfo() override {
        cout << "[Critica] " << nombre << " | " << potencia << " kW | Estado: " << (estado ? "ENCENDIDA" : "APAGADA") << endl;
    }
};