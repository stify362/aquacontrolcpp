#include <iostream>
#include "Carga.h"
#include "CargaCritica.h"
#include "CargaAplazable.h"
#include "Medidor.h"
#include "Mercado.h"
#include "Negocio.h"

using namespace std;

int main() {
    Negocio panaderia("Panaderia Artesanal WattControl");
    Mercado mercado;
    int opcion;
    int hora;
    float precio;

    do {
        cout << "\n==============================\n";
        cout << "    SISTEMA WATTCONTROL - MENÚ\n";
        cout << "==============================\n";
        cout << "1. Ver estado de la panaderia\n";
        cout << "2. Simular condiciones del entorno (Hora / Precio)\n";
        cout << "3. Ejecutar reglas de control automaticas\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                panaderia.mostrarEstadoNegocio(mercado.getHoraActual(), mercado.getPrecioBolsa());
                break;
            case 2:
                cout << "Ingrese la hora actual (0-23): ";
                cin >> hora;
                cout << "Ingrese el precio de bolsa (COP/kWh): ";
                cin >> precio;
                mercado.setHoraActual(hora);
                mercado.setPrecioBolsa(precio);
                cout << "[INFO] Entorno actualizado correctamente.\n";
                break;
            case 3:
                panaderia.evaluarReglasControl(mercado.getHoraActual(), mercado.getPrecioBolsa());
                break;
            case 4:
                cout << "Saliendo del sistema WattControl...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while(opcion != 4);

    return 0;
}