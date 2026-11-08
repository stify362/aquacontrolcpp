#pragma once
#include <iostream>
#include "Carga.h"

using namespace std;

class Medidor {
private:
    float potenciaContratada; // Límite para la panadería: 9.0 kW

public:
    Medidor(float limite = 9.0) : potenciaContratada(limite) {}

    // Suma la potencia de todas las cargas que estén encendidas actualmente
    float calcularPotenciaTotal(Carga* cargas[], int numCargas) {
        float total = 0;
        for (int i = 0; i < numCargas; i++) {
            if (cargas[i]->getEstado()) {
                total += cargas[i]->getPotencia();
            }
        }
        return total;
    }

    // Valida si la potencia activa supera el límite contratado
    bool validarSobrecarga(float potenciaActual) {
        if (potenciaActual > potenciaContratada) {
            cout << "[ALERTA DE MEDIDOR] ¡Sobrecarga detectada! (" << potenciaActual 
                 << " kW > " << potenciaContratada << " kW contratados).\n";
            return true;
        }
        return false;
    }

    float getPotenciaContratada() { return potenciaContratada; }
};