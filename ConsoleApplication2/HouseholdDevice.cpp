#include "HouseholdDevice.h"
#include <iostream>

HouseholdDevice::HouseholdDevice()
    : brand(""), model(""), weight(0), year(0), power(0), isOn(false), currentMode(0) {}

HouseholdDevice::HouseholdDevice(const std::string& brand, const std::string& model,
    double weight, int year, int power)
    : brand(brand), model(model), weight(weight), year(year), power(power), isOn(false), currentMode(0) {}

void HouseholdDevice::printInfo() const {
    std::cout << "Бренд: " << brand << std::endl;
    std::cout << "Модель: " << model << std::endl;
    std::cout << "Вес: " << weight << " кг" << std::endl;
    std::cout << "Год выпуска: " << year << std::endl;
    std::cout << "Мощность: " << power << " Вт" << std::endl;
    std::cout << "Состояние: " << (isOn ? "включен" : "выключен") << std::endl;
    std::cout << "Текущий режим: " << currentMode << std::endl;
}
