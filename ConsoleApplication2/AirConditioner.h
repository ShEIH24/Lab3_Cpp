#ifndef AIR_CONDITIONER_H
#define AIR_CONDITIONER_H

#include "HouseholdDevice.h"
#include <string>

class AirConditioner : public HouseholdDevice {
private:
    double temperature;
    double totalTempChange;
    int settingsCount;

public:
    AirConditioner();
    AirConditioner(const std::string& brand, const std::string& model,
        double weight, int year, int power);

    void control(int temperature) override;
    void setTemperature(double temperature);
    double getTemperature() const { return temperature; }
    double getAverageTemperatureChange() const;

    void serialize() const;
    void deserialize();
    void serialize(const std::string& filename) const;
    void deserialize(const std::string& filename);

    void printInfo() const override;
};

#endif