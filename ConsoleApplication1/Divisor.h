#ifndef DIVISOR_H
#define DIVISOR_H

#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <sstream>
#include <algorithm>
#include <cmath>

// ����� ��� ���������� �������� ���� ���������
class Divisor : public ExpressionEvaluator, public IShuffle {
public:
    explicit Divisor(size_t n) : ExpressionEvaluator(n) {}

    // ���������� ���������� �������
    double calculate() override {
        if (operandsCount == 0) return 0;

        // �������� ������� �� ����
        for (size_t i = 0; i < operandsCount; ++i) {
            if (i > 0 && operands[i] == 0) return 0;
        }

        double result = operands[0];
        for (size_t i = 1; i < operandsCount; ++i) {
            result /= operands[i];
        }
        return result;
    }

    // ���������� ��������� �� �����������
    void shuffle() override {
        std::sort(operands, operands + operandsCount);
    }

    // ����������� ��������� ���� ���� ������� �����
    void shuffle(size_t i, size_t j) override {
        if (i >= operandsCount || j >= operandsCount) return;

        double fractI = operands[i] - std::floor(operands[i]);
        double fractJ = operands[j] - std::floor(operands[j]);

        if (fractI > 0 || fractJ > 0) {
            std::swap(operands[i], operands[j]);
        }
    }

protected:
    // ������������ ������ ���������
    std::string getExpressionString() const override {
        std::ostringstream oss;
        for (size_t i = 0; i < operandsCount; ++i) {
            if (i > 0) oss << " / ";
            oss << operands[i];
        }
        return oss.str();
    }
};

#endif