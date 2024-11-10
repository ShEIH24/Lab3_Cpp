#include "Heater.h"
#include <iostream>

Heater::Heater() : temperature(0), hasThermostat(true) {}

Heater::Heater(const std::string& brand, const std::string& model,
    double weight, int year, int power, bool hasThermostat)
    : HouseholdDevice(brand, model, weight, year, power),
    temperature(0), hasThermostat(hasThermostat) {}

void Heater::control(int temperature) {
    if (temperature > 45) {
        std::cout << "����������� ������� �������. ������������ ����������� ��� ������������." << std::endl;
        turnOff();
        currentMode = 0;
    }
    else {
        turnOn();
        if (temperature < 20) {
            currentMode = 3; // ������� ������
            std::cout << "����������� ������. ������� ����� �������� �������." << std::endl;
        }
        else if (temperature < 30) {
            currentMode = 2; // ������� ������
            std::cout << "������� ����� �������� �������." << std::endl;
        }
        else {
            currentMode = 1; // ������ ������
            std::cout << "����������� ������ � �������. ������� ����� ������� �������." << std::endl;
        }
        setTemperature(temperature);
        std::cout << "������������ ���������� �� ����� " << currentMode <<
            " � ������� ������������ " << temperature << "�C" << std::endl;
    }
}

void Heater::setTemperature(double temp) {
    temperature = temp;
}

void Heater::printInfo() const {
    HouseholdDevice::printInfo();
    std::cout << "������� ������� �����������: " << temperature << "�C" << std::endl;
    std::cout << "������� ����������: " << (hasThermostat ? "��" : "���") << std::endl;
    std::cout << "������� ����� ������: ";
    switch (currentMode) {
    case 0: std::cout << "��������"; break;
    case 1: std::cout << "������ ������"; break;
    case 2: std::cout << "������� ������"; break;
    case 3: std::cout << "������� ������"; break;
    default: std::cout << "����������";
    }
    std::cout << std::endl;
}