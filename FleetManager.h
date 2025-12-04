#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>   
#include <iomanip>   

#include "FleetFrame.h"

using namespace std;

class FleetManager {
private:
    vector<FleetRecord> records;

public:
    FleetManager(vector<FleetRecord> data) : records(data) {}

    void showAll() const {
        cout << "\n--- REPORTE COMPLETO DE FLOTA ---" << endl;
        for (const auto& rec : records) {
            cout << rec << endl;
        }
        cout << "Total registros: " << records.size() << endl;
    }


    void sortByEfficiency() {
        sort(records.begin(), records.end(), [](const FleetRecord& a, const FleetRecord& b) {
            double effA = (a.energy > 0) ? (a.distance / a.energy) : 0;
            double effB = (b.energy > 0) ? (b.distance / b.energy) : 0;
            return effA > effB; 
        });
        cout << ">> Flota re-ordenada por eficiencia (Km/kWh)." << endl;
    }

    void showIncidents() {
        cout << "\n--- REPORTE DE INCIDENTES ---" << endl;
        int count = 0;
        for (const auto& rec : records) {
            if (rec.status == driveStatus::Incidente) {
                cout << "[ALERTA] " << rec.model << " (" << rec.date << ") en ruta " 
                     << rec.origin << "->" << rec.destination << endl;
                count++;
            }
        }
        if (count == 0) cout << "Sin incidentes registrados." << endl;
    }


    void showGlobalStats() {
        double totalDist = 0;
        double totalEnergy = 0;
        double totalWeight = 0;

        for (const auto& rec : records) {
            totalDist += rec.distance;
            totalEnergy += rec.energy;
            totalWeight += rec.weight;
        }

        cout << "\n--- ESTADISTICAS GLOBALES ---" << endl;
        cout << "Distancia Total Recorrida: " << totalDist << " km" << endl;
        cout << "Energia Total Consumida:   " << totalEnergy << " kWh" << endl;
        cout << "Carga Total Transportada:  " << totalWeight << " kg" << endl;
        
        if (totalEnergy > 0)
            cout << "Eficiencia Promedio:     " << (totalDist/totalEnergy) << " km/kWh" << endl;
    }
};