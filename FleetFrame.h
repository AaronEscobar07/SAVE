#pragma once

#include <string>
#include <iostream>
using namespace std;

#include "Fleet_Enum.h"

// struct main
struct FleetRecord {
    string id;           // ID del vehiculo (rank)
    string model;        // Modelo del vehiculo (name)
    vehicleType type;    // Enum tipo de vehiculo
    string date;         // Fecha del viaje (year)
    double distance;     // Distancia recorrida
    double energy;       // Energia consumida
    double weight;       // Peso de carga
    driveStatus status;      // Enum estado del viaje
    string origin;       // Ciudad de salida
    string destination;  // Ciudad destino

    // Sobrecarga operador << para imprimir registro
    friend ostream& operator<<(ostream& os, const FleetRecord& fr) {
        os << "#" << fr.id << " | "
           << "[" << fr.date << "] " 
           << fr.model 
           << " (" << vehicleTypeToString(fr.type) << ") - "
           << driveStatusToString(fr.status) 
           << " | Ruta: " << fr.origin << " -> " << fr.destination
           << " | Carga: " << fr.weight << "kg"
           << " | Consumo: " << fr.distance << "km / " << fr.energy << "kWh";
        return os;
    }
};