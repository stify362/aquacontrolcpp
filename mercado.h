#pragma once

class Mercado {
private:
    float precioBolsaActual;
    int horaActual;

public:
    Mercado(float precio = 500.0, int hora = 10) : precioBolsaActual(precio), horaActual(hora) {}

    void setPrecioBolsa(float p) { precioBolsaActual = p; }
    void setHoraActual(int h) { horaActual = h; }

    float getPrecioBolsa() { return precioBolsaActual; }
    int getHoraActual() { return horaActual; }

    bool esHoraPico() {
        return (horaActual >= 18 && horaActual <= 20); // 6 PM a 8 PM
    }

    bool esPrecioAlto() {
        return (precioBolsaActual > 800.0); // Umbral de 800 COP/kWh
    }
};