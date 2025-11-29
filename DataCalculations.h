//
// Created by alann on 11/29/2025.
//

#ifndef SENSORDATAANALYZER_DATACALCULATIONS_H
#define SENSORDATAANALYZER_DATACALCULATIONS_H
#include <vector>
#include <functional>
#include "FlightInstance.h"
using namespace std;


class DataCalculations {
private:
    const vector<FlightInstance>& data;

public:
    DataCalculations(const vector<FlightInstance>& d);

    double mean(function<double(const FlightInstance&)> getter);
    double standardDev(function<double(const FlightInstance&)> getter);
    double min(function<double(const FlightInstance&)> getter);
    double max(function<double(const FlightInstance&)> getter);

    void vibrationAnomalies();
};


#endif //SENSORDATAANALYZER_DATACALCULATIONS_H