//
// Created by Alanna on 11/29/2025.
//

#ifndef SENSORDATAANALYZER_FLIGHTINSTANCE_H
#define SENSORDATAANALYZER_FLIGHTINSTANCE_H
#include <string>
using namespace std;


class FlightInstance {
    public:
    string timestamp, engine_id, flight_phase, status;
    double altitude_ft, airspeed_kts, oil_temp_c, vibration_g, fuel_flow_kg_per_hr;
};


#endif //SENSORDATAANALYZER_FLIGHTINSTANCE_H