#ifndef CUSTOM_EXPRESSION_EVALUATOR_H
#define CUSTOM_EXPRESSION_EVALUATOR_H

#include "ExpressionEvaluator.h"
#include <sstream>

// Класс для вычисления выражения вида x1 + x2*x3 + x4*x5 + ...
class CustomExpressionEvaluator : public ExpressionEvaluator {
public:
    explicit CustomExpressionEvaluator(size_t n) : ExpressionEvaluator(n) {}

    // Вычисление результата пользовательского выражения
    double calculate() override {
        double result = operands[0];
        for (size_t i = 1; i < operandsCount - 1; i += 2) {
            result += operands[i] * operands[i + 1];
        }
        if (operandsCount % 2 == 0) {
            result += operands[operandsCount - 1];
        }
        return result;
    }

protected:
    // Формирование строки выражения
    std::string getExpressionString() const override {
        std::ostringstream oss;
        oss << operands[0];
        for (size_t i = 1; i < operandsCount - 1; i += 2) {
            oss << " + " << operands[i] << "*" << operands[i + 1];
        }
        if (operandsCount % 2 == 0) {
            oss << " + " << operands[operandsCount - 1];
        }
        return oss.str();
    }
};

#endif