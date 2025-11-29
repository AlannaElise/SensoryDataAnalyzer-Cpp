//
// Created by alann on 11/29/2025.
//

#include "DataCalculations.h"
#include <cmath>
#include <functional>
#include <iostream>
#include "FlightInstance.h"
#include <vector>

DataCalculations::DataCalculations(const vector<FlightInstance>& d) : data(d) {}

double DataCalculations::min(function<double(const FlightInstance&)> getter) {
    double min = getter(data[0]);
    for (const auto& f : data) {
        double val = getter(f);
        if (val < min)
            min = val;
    }
    return min;
}

double DataCalculations::max(function<double(const FlightInstance&)> getter) {
    double max = getter(data[0]);
    for (const auto& f : data) {
        double val = getter(f);
        if (val > max)
            max = val;
    }
    return max;
}

double DataCalculations::mean(function<double(const FlightInstance&)> getter) {
    double sum = 0;
    for (const auto& f : data) {
        sum += getter(f);
    }
    return sum / data.size();
}

double DataCalculations::standardDev(function<double(const FlightInstance&)> getter) {
    double m = mean(getter);
    double sum_squared_diff = 0;

    for (const auto& f : data) {
        double val = getter(f);
        sum_squared_diff += (val - m) * (val - m);
    }

    return sqrt(sum_squared_diff / (data.size() - 1));
}

void DataCalculations::vibrationAnomalies() {
    double m = mean([](const FlightInstance& f) { return f.vibration_g; });
    double s = standardDev([](const FlightInstance& f) { return f.vibration_g; });

    cout << "Anomalies:" << endl;

    for (const auto& f : data) {
        double val = f.vibration_g;

        if (val > (m + 2 * s) || val < (m - 2 * s)) {
            cout << "Anomaly at " << f.timestamp << ": " << val << "g" << endl;
        }
    }
}