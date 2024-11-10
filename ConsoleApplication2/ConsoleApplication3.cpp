#include "AirConditioner.h"
#include "Heater.h"
#include <iostream>
#include <iomanip>
#include <vector>

void printLine() {
    std::cout << "\n----------------------------------------\n";
}

void demonstrateDevice(const std::string& deviceName, HouseholdDevice& device,
    std::vector<int> temperatures) {
    printLine();
    std::cout << "=== Демонстрация работы устройства: " << deviceName << " ===" << std::endl;

    std::cout << "\nНачальное состояние устройства:" << std::endl;
    device.printInfo();

    for (int temp : temperatures) {
        printLine();
        std::cout << "Тест: Установка температуры " << temp << "°C" << std::endl;
        device.control(temp);
        device.printInfo();
    }
}

void demonstrateClimateControl() {
    // Создаем устройства
    AirConditioner premiumAC("Samsung", "WindFree Premium", 12.5, 2024, 2200);
    Heater smartHeater("Ballu", "Smart Pro", 5.2, 2024, 2500, true);

    // Температуры для тестирования кондиционера
    std::vector<int> acTemperatures = {
        5,    // Слишком холодно - должен выключиться
        22,   // Комфортная температура - среднее охлаждение
        26,   // Жарко - сильное охлаждение
        20    // Возврат к комфортной температуре
    };

    // Температуры для тестирования обогревателя
    std::vector<int> heaterTemperatures = {
        50,   // Слишком горячо - должен выключиться
        18,   // Прохладно - сильный нагрев
        25,   // Комфортная температура - средний нагрев
        15    // Холодно - сильный нагрев
    };

    std::cout << "\n=== ТЕСТИРОВАНИЕ КЛИМАТИЧЕСКОГО ОБОРУДОВАНИЯ ===\n" << std::endl;

    // Демонстрация кондиционера
    demonstrateDevice("Кондиционер Samsung WindFree Premium", premiumAC, acTemperatures);

    // Демонстрация обогревателя
    demonstrateDevice("Обогреватель Ballu Smart Pro", smartHeater, heaterTemperatures);

    // Итоговая статистика
    printLine();
    std::cout << "=== ИТОГОВАЯ СТАТИСТИКА ===\n" << std::endl;

    if (auto* ac = dynamic_cast<AirConditioner*>(&premiumAC)) {
        std::cout << "Кондиционер - среднее изменение температуры: "
            << std::fixed << std::setprecision(2)
            << ac->getAverageTemperatureChange() << "°C" << std::endl;
    }

    std::cout << "\nСтатус устройств:" << std::endl;
    std::cout << "Кондиционер: " << (premiumAC.getIsOn() ? "включен" : "выключен")
        << ", режим " << premiumAC.getCurrentMode() << std::endl;
    std::cout << "Обогреватель: " << (smartHeater.getIsOn() ? "включен" : "выключен")
        << ", режим " << smartHeater.getCurrentMode() << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    demonstrateClimateControl();
    return 0;
}