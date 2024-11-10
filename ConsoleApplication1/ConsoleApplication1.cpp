#include "Divisor.h"
#include "CustomExpressionEvaluator.h"
#include "Multiplier.h"
#include <iostream>
#include <typeinfo>

int main() {
    setlocale(LC_ALL, "Russian");

    // Создаем массив указателей на базовый класс
    ExpressionEvaluator* expressions[3];

    // Создаем объекты согласно варианту
    expressions[0] = new Divisor(4);
    expressions[1] = new CustomExpressionEvaluator(5);
    expressions[2] = new Multiplier(5);

    // Инициализация Divisor поэлементно
    expressions[0]->setOperand(0, 150);
    expressions[0]->setOperand(1, -3);
    expressions[0]->setOperand(2, 10);
    expressions[0]->setOperand(3, -2.5);

    // Инициализация CustomExpressionEvaluator группой значений
    double customValues[] = {5, 16, -3, 10, 12};
    expressions[1]->setOperands(customValues, 5);

    // Инициализация Multiplier группой значений
    double multiplierValues[] = {1.5, 4, -2.5, -8, -15};
    expressions[2]->setOperands(multiplierValues, 5);

    // Демонстрация полиморфизма
    std::cout << "Исходные выражения и их результаты:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        expressions[i]->logToScreen();
        expressions[i]->logToFile("expressions.log");
        std::cout << std::endl;
    }

    // Демонстрация работы с интерфейсом IShuffle
    std::cout << "\nПроверка функционала перемешивания:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        IShuffle* shuffleable = dynamic_cast<IShuffle*>(expressions[i]);
        if (shuffleable) {
            std::cout << "До перемешивания: " << std::endl;
            expressions[i]->logToScreen();
            
            shuffleable->shuffle();
            
            std::cout << "После перемешивания: " << std::endl;
            expressions[i]->logToScreen();
            
            shuffleable->shuffle(0, 1);
            std::cout << "После перемешивания(0,1): " << std::endl;
            expressions[i]->logToScreen();
            
            std::cout << std::endl;
        }
    }

    // Освобождение памяти
    for (int i = 0; i < 3; ++i) {
        delete expressions[i];
    }

    return 0;
}