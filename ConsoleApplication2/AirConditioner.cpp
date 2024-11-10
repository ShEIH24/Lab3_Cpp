#include "AirConditioner.h"
#include <iostream>

AirConditioner::AirConditioner()
    : temperature(0), totalTempChange(0), settingsCount(0) {}

AirConditioner::AirConditioner(const std::string& brand, const std::string& model,
    double weight, int year, int power)
    : HouseholdDevice(brand, model, weight, year, power),
    temperature(0), totalTempChange(0), settingsCount(0) {}

void AirConditioner::control(int temperature) {
    if (temperature < 10) {
        std::cout << "Температура слишком низкая. Кондиционер выключается." << std::endl;
        turnOff();
        currentMode = 0;
    }
    else {
        turnOn();
        if (temperature < 18) {
            currentMode = 1; // Слабое охлаждение
        }
        else if (temperature < 24) {
            currentMode = 2; // Среднее охлаждение
        }
        else {
            currentMode = 3; // Сильное охлаждение
        }
        setTemperature(temperature);
        std::cout << "Кондиционер установлен на режим " << currentMode <<
            " с температурой " << temperature << "°C" << std::endl;
    }
}

void AirConditioner::setTemperature(double temp) {
    totalTempChange += std::abs(temp - temperature);
    temperature = temp;
    settingsCount++;
}

double AirConditioner::getAverageTemperatureChange() const {
    return settingsCount > 0 ? totalTempChange / settingsCount : 0;
}

void AirConditioner::printInfo() const {
    HouseholdDevice::printInfo();
    std::cout << "Текущая температура: " << temperature << "°C" << std::endl;
    std::cout << "Среднее изменение температуры: " << getAverageTemperatureChange() << "°C" << std::endl;
}

// Пустые реализации для сериализации (можно добавить реальную функциональность позже)
void AirConditioner::serialize() const {}
void AirConditioner::deserialize() {}
void AirConditioner::serialize(const std::string&) const {}
void AirConditioner::deserialize(const std::string&) {}