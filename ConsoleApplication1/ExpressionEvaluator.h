#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include "ILoggable.h"
#include <cstddef>
#include <string>
#include <fstream>
#include <iostream>

// Абстрактный базовый класс для вычисления выражений
class ExpressionEvaluator : public ILoggable {
protected:
    double* operands;        // Массив операндов
    size_t operandsCount;    // Количество операндов

public:
    // Конструктор по умолчанию - выделяет память под 20 операндов
    ExpressionEvaluator() : operandsCount(20) {
        operands = new double[operandsCount]();
    }

    // Конструктор с параметром - выделяет память под n операндов
    explicit ExpressionEvaluator(size_t n) : operandsCount(n) {
        operands = new double[operandsCount]();
    }

    // Виртуальный деструктор для освобождения памяти
    virtual ~ExpressionEvaluator() {
        delete[] operands;
    }

    // Чисто виртуальная функция для вычисления результата выражения
    virtual double calculate() = 0;

    // Установка значения одного операнда
    void setOperand(size_t pos, double value) {
        if (pos < operandsCount) {
            operands[pos] = value;
        }
    }

    // Установка значений группы операндов
    void setOperands(double ops[], size_t n) {
        size_t count = std::min(n, operandsCount);
        for (size_t i = 0; i < count; ++i) {
            operands[i] = ops[i];
        }
    }

    // Запись выражения в файл
    void logToFile(const std::string& filename) override {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << getExpressionString() << " < Total " << operandsCount << " > " << std::endl;
            file << "< Result " << calculate() << " >" << std::endl;
            file.close();
        }
    }

    // Вывод выражения на экран
    void logToScreen() override {
        std::cout << getExpressionString() << " < Total " << operandsCount << " > " << std::endl;
        std::cout << "< Result " << calculate() << " >" << std::endl;
    }

protected:
    // Виртуальная функция для получения строкового представления выражения
    virtual std::string getExpressionString() const = 0;
};

#endif