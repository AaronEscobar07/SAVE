#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <filesystem> 
#include <string_view> 

#include "FleetFrame.h" 

using namespace std;

class FileHandler {
public:
    static vector<string> split(string_view str, char delimiter) {
        vector<string> tokens;
        string token;
        string strCopy(str); 
        istringstream tokenStream(strCopy);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    static vector<FleetRecord> loadFromCSV(const string& filename) {
        vector<FleetRecord> data;

        if (!filesystem::exists(filename)) {
            cerr << "[ERROR] El archivo " << filename << " no existe en la ruta actual." << endl;
            return data;
        }

        ifstream file(filename);
        string line;

        getline(file, line);

        while (getline(file, line)) {
            if(line.empty()) continue;

            try {
                vector<string> tokens = split(line, ',');

                if (tokens.size() < 10) {
                    continue; 
                }

                FleetRecord record;

                record.id = tokens[0];
                record.model = tokens[1];
                
                record.type = stringToVehicleType(tokens[2]); 
                
                record.date = tokens[3];
                
                record.distance = stod(tokens[4]);
                record.energy = stod(tokens[5]);
                record.weight = stod(tokens[6]);
                
                record.status = stringToDStatus(tokens[7]);
                
                record.origin = tokens[8];
                record.destination = tokens[9];

                data.push_back(record);

            } catch (const exception& e) {
                cerr << "[ALERTA] Error parseando linea: " << line << " | " << e.what() << endl;
            }
        }

        cout << "-> Carga completada: " << data.size() << " registros importados." << endl;
        return data;
    }
};