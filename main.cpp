#include <iostream>
#include <limits>
#include "FileHandler.h"
#include "FleetManager.h"

using namespace std;

void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "                 S.A.V.E        " << endl;
    cout << "========================================" << endl;
    cout << "1. Mostrar todos los registros" << endl;
    cout << "2. Ver Estadisticas Globales" << endl;
    cout << "3. Reporte de Incidentes" << endl;
    cout << "4. Ordenar flota por Eficiencia (Mejor a Peor)" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    string archivo = "fleet.csv";
    
    cout << "Cargando base de datos..." << endl;
    vector<FleetRecord> datos = FileHandler::loadFromCSV(archivo);

    if (datos.empty()) {
        cout << "Error critico: No hay datos para procesar." << endl;
        return 1;
    }

    FleetManager manager(datos);
    int opcion = 0;

    while (opcion != 5) {
        mostrarMenu();
        if (!(cin >> opcion)) { 
            cout << "Entrada invalida. Ingrese un numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                manager.showAll();
                break;
            case 2:
                manager.showGlobalStats();
                break;
            case 3:
                manager.showIncidents();
                break;
            case 4:
                manager.sortByEfficiency();
                manager.showAll();
                break;
            case 5:
                cout << "Cerrando sistema... Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    }

    return 0;
}