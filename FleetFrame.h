#pragma once

#include <string>
#include <iostream>
using namespace std;

// enum Tipo de Vehiculo
enum class vehicleType {
    Sedan,
    SUV,
    Camioneta,
    Otro
};

// enum Status del viaje
enum class driveStatus {
    Completado,
    Cancelado,
    Incidente, 
    Desconocido
};

// Convertidor de Tipo de Vehiculo a string
inline string vehicleTypeToString(vehicleType type) {
    switch (type) {
        case vehicleType::Sedan: return "Sedan";
        case vehicleType::SUV: return "SUV";
        case vehicleType::Camioneta: return "Camioneta";
        default: return "Otro";
    }
}

inline vehicleType stringToVehicleType(const string& str) {
    if (str == "Sedan") return vehicleType::Sedan;
    if (str == "SUV") return vehicleType::SUV;
    if (str == "Camioneta") return vehicleType::Camioneta;
    return vehicleType::Otro;
}

// Convertidor de Status a string
inline string dStatusToString(driveStatus status) {
    switch (status) {
        case driveStatus::Completado: return "Completado";
        case driveStatus::Cancelado: return "Cancelado";
        case driveStatus::Incidente: return "Incidente";
        default: return "Desconocido";
    }
}

inline dStatus stringToDStatus(const string& str) {
    if (str == "Completado") return dStatus::Completado;
    if (str == "Cancelado") return dStatus::Cancelado;
    if (str == "Incidente") return dStatus::Incidente;
    return dStatus::Desconocido;
}

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
           << dStatusToString(fr.status) 
           << " | Ruta: " << fr.origin << " -> " << fr.destination
           << " | Carga: " << fr.weight << "kg"
           << " | Consumo: " << fr.distance << "km / " << fr.energy << "kWh";
        return os;
    }
};