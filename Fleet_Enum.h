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
inline string driveStatusToString(driveStatus status) {
    switch (status) {
        case driveStatus::Completado: return "Completado";
        case driveStatus::Cancelado: return "Cancelado";
        case driveStatus::Incidente: return "Incidente";
        default: return "Desconocido";
    }
}

inline driveStatus stringToDStatus(const string& str) {
    if (str == "Completado") return driveStatus::Completado;
    if (str == "Cancelado") return driveStatus::Cancelado;
    if (str == "Incidente") return driveStatus::Incidente;
    return driveStatus::Desconocido;
}
