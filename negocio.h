#pragma once
#include <iostream>
#include <string>
#include "Carga.h"
#include "CargaCritica.h"
#include "CargaAplazable.h"
#include "Medidor.h"

using namespace std;

class Negocio {
private:
    string nombreComercial;
    Carga* cargas[3]; // [0]: Nevera (Crítica), [1]: Horno (Aplazable), [2]: Amasadora (Aplazable)
    Medidor medidor;

public:
    Negocio(string nombre) : nombreComercial(nombre), medidor(9.0) {
        // Inicializamos los equipos específicos de la panadería con sus potencias
        cargas[0] = new CargaCritica("Nevera de Insumos", 1.2);    // 1.2 kW
        cargas[1] = new CargaAplazable("Horno Electrico", 7.0);     // 7.0 kW
        cargas[2] = new CargaAplazable("Amasadora", 2.2);          // 2.2 kW
    }

    ~Negocio() {
        // Liberar la memoria dinámica de las cargas
        for (int i = 0; i < 3; i++) {
            delete cargas[i];
        }
    }

    // Muestra en consola el estado actual de cada equipo y la potencia total consumida
    void mostrarEstadoNegocio(int horaActual, float precioBolsa) {
        cout << "\n========================================\n";
        cout << " WATTCONTROL: " << nombreComercial << " | Hora: " << horaActual << ":00 h\n";
        cout << " Precio Bolsa: " << precioBolsa << " COP/kWh\n";
        cout << "========================================\n";
        
        for (int i = 0; i < 3; i++) {
            cargas[i]->mostrarInfo();
        }

        float potenciaTotal = medidor.calcularPotenciaTotal(cargas, 3);
        cout << "----------------------------------------\n";
        cout << " Potencia Activa Total: " << potenciaTotal << " kW / " << medidor.getPotenciaContratada() << " kW\n";
        cout << "========================================\n";
    }

    // Aplica la lógica de control automatizado según el entorno
    void evaluarReglasControl(int horaActual, float precioBolsa) {
        bool esHoraPico = (horaActual >= 18 && horaActual <= 20); // 6:00 PM a 8:00 PM
        bool precioAlto = (precioBolsa > 800.0);                   // Umbral de 800 COP/kWh

        if (esHoraPico || precioAlto) {
            cout << "\n[CONTROL AUTOMATICO] Condicion critica detectada (" 
                 << (esHoraPico ? "Hora Pico" : "Precio Alto") << "). Apagando cargas aplazables...\n";
            cargas[1]->setEstado(false); // Apagar Horno (7.0 kW)
            cargas[2]->setEstado(false); // Apagar Amasadora (2.2 kW)
        } else {
            // Si las condiciones son normales, se pueden encender de nuevo
            cargas[1]->setEstado(true);
            cargas[2]->setEstado(true);
        }

        // Validación adicional por si la suma supera los 9 kW contratados
        float potenciaTotal = medidor.calcularPotenciaTotal(cargas, 3);
        if (medidor.validarSobrecarga(potenciaTotal)) {
            cout << "[ACCION DE EMERGENCIA] Excede potencia contratada. Apagando carga aplazable mayor (Horno)...\n";
            cargas[1]->setEstado(false);
        }
    }
};