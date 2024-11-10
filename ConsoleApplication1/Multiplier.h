#ifndef MULTIPLIER_H
#define MULTIPLIER_H

#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <sstream>
#include <algorithm>
#include <cmath>

// Класс для вычисления произведения всех операндов
class Multiplier : public ExpressionEvaluator, public IShuffle {
public:
    explicit Multiplier(size_t n) : ExpressionEvaluator(n) {}

    // Вычисление результата умножения
    double calculate() override {
        double result = 1.0;
        for (size_t i = 0; i < operandsCount; ++i) {
            result *= operands[i];
        }
        return result;
    }

    // Сортировка операндов по возрастанию
    void shuffle() override {
        std::sort(operands, operands + operandsCount);
    }

    // Перемещение операндов если есть дробная часть
    void shuffle(size_t i, size_t j) override {
        if (i >= operandsCount || j >= operandsCount) return;

        double fractI = operands[i] - std::floor(operands[i]);
        double fractJ = operands[j] - std::floor(operands[j]);

        if (fractI > 0 || fractJ > 0) {
            std::swap(operands[i], operands[j]);
        }
    }

protected:
    // Формирование строки выражения
    std::string getExpressionString() const override {
        std::ostringstream oss;
        for (size_t i = 0; i < operandsCount; ++i) {
            if (i > 0) oss << " * ";
            oss << operands[i];
        }
        return oss.str();
    }
};

#endif