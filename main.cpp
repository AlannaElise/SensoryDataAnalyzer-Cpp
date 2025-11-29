#include <cmath>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <functional>
#include <sstream>
#include <vector>
#include "FlightInstance.h"
#include "DataCalculations.h"
using namespace std;


int main() {
    fstream file;
    string line;
    vector<FlightInstance> flight_vector;
    FlightInstance flight;

    string filename = "sensor_data_analyzer_sample.csv";
    file.open(filename, ios::in);


    if (!file.is_open()) {
        cout << "Failed to open file!" << endl;
        return 1;
    }

    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;

        getline(ss, flight.timestamp, ',');
        getline(ss, flight.engine_id, ',');
        getline(ss, flight.flight_phase, ',');
        getline(ss, temp, ',');
        flight.altitude_ft = stod(temp);
        getline(ss, temp, ',');
        flight.airspeed_kts = stod(temp);
        getline(ss, temp, ',');
        flight.oil_temp_c = stod(temp);
        getline(ss, temp, ',');
        flight.vibration_g = stod(temp);
        getline(ss, temp, ',');
        flight.fuel_flow_kg_per_hr = stod(temp);
        getline(ss, flight.status, ',');

        flight_vector.push_back(flight);

        }

    DataCalculations analyzer(flight_vector);

    double minOilTemp = analyzer.min([](const FlightInstance& f) { return f.oil_temp_c; });
    double maxOilTemp = analyzer.max([](const FlightInstance& f) { return f.oil_temp_c; });

    double minVibration = analyzer.min([](const FlightInstance& f) { return f.vibration_g; });
    double maxVibration = analyzer.max([](const FlightInstance& f) { return f.vibration_g; });

    double meanFuelFlow = analyzer.mean([](const FlightInstance& f) { return f.fuel_flow_kg_per_hr; });

    double vibrationStandardDev = analyzer.standardDev([](const FlightInstance& f) { return f.vibration_g; });

    cout << "Minimum Oil Temperature (c): " << minOilTemp << endl;
    cout << "Maximum Oil Temperature (c): " << maxOilTemp << endl;
    cout << "Minimum Vibration (g): " << minVibration << endl;
    cout << "Maximum Vibration (g): " << maxVibration << endl;
    cout << "Mean Fuel Flow (kg): " << meanFuelFlow << endl;
    cout << "Vibration Standard Deviation (g): " << vibrationStandardDev << endl;
    cout << endl;

    analyzer.vibrationAnomalies();

    return 0;
}