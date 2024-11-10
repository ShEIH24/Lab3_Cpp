#include "HouseholdDevice.h"
#include <iostream>

HouseholdDevice::HouseholdDevice()
    : brand(""), model(""), weight(0), year(0), power(0), isOn(false), currentMode(0) {}

HouseholdDevice::HouseholdDevice(const std::string& brand, const std::string& model,
    double weight, int year, int power)
    : brand(brand), model(model), weight(weight), year(year), power(power), isOn(false), currentMode(0) {}

void HouseholdDevice::printInfo() const {
    std::cout << "�����: " << brand << std::endl;
    std::cout << "������: " << model << std::endl;
    std::cout << "���: " << weight << " ��" << std::endl;
    std::cout << "��� �������: " << year << std::endl;
    std::cout << "��������: " << power << " ��" << std::endl;
    std::cout << "���������: " << (isOn ? "�������" : "��������") << std::endl;
    std::cout << "������� �����: " << currentMode << std::endl;
}
