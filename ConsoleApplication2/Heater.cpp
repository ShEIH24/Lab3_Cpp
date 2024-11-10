#include "Heater.h"
#include <iostream>

Heater::Heater() : temperature(0), hasThermostat(true) {}

Heater::Heater(const std::string& brand, const std::string& model,
    double weight, int year, int power, bool hasThermostat)
    : HouseholdDevice(brand, model, weight, year, power),
    temperature(0), hasThermostat(hasThermostat) {}

void Heater::control(int temperature) {
    if (temperature > 45) {
        std::cout << "Температура слишком высокая. Обогреватель выключается для безопасности." << std::endl;
        turnOff();
        currentMode = 0;
    }
    else {
        turnOn();
        if (temperature < 20) {
            currentMode = 3; // Сильный нагрев
            std::cout << "Температура низкая. Включен режим сильного нагрева." << std::endl;
        }
        else if (temperature < 30) {
            currentMode = 2; // Средний нагрев
            std::cout << "Включен режим среднего нагрева." << std::endl;
        }
        else {
            currentMode = 1; // Слабый нагрев
            std::cout << "Температура близка к целевой. Включен режим слабого нагрева." << std::endl;
        }
        setTemperature(temperature);
        std::cout << "Обогреватель установлен на режим " << currentMode <<
            " с целевой температурой " << temperature << "°C" << std::endl;
    }
}

void Heater::setTemperature(double temp) {
    temperature = temp;
}

void Heater::printInfo() const {
    HouseholdDevice::printInfo();
    std::cout << "Текущая целевая температура: " << temperature << "°C" << std::endl;
    std::cout << "Наличие термостата: " << (hasThermostat ? "да" : "нет") << std::endl;
    std::cout << "Текущий режим работы: ";
    switch (currentMode) {
    case 0: std::cout << "выключен"; break;
    case 1: std::cout << "слабый нагрев"; break;
    case 2: std::cout << "средний нагрев"; break;
    case 3: std::cout << "сильный нагрев"; break;
    default: std::cout << "неизвестен";
    }
    std::cout << std::endl;
}