#ifndef HEATER_H
#define HEATER_H

#include "HouseholdDevice.h"
#include <string>

class Heater : public HouseholdDevice {
private:
    double temperature;
    bool hasThermostat;

public:
    // Конструкторы
    Heater();
    Heater(const std::string& brand, const std::string& model,
        double weight, int year, int power, bool hasThermostat = true);

    // Методы управления
    void control(int temperature) override;
    void setTemperature(double temperature);
    double getTemperature() const { return temperature; }
    bool getHasThermostat() const { return hasThermostat; }

    // Вывод информации
    void printInfo() const override;
};

#endif