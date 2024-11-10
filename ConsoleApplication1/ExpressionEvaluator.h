#ifndef EXPRESSION_EVALUATOR_H
#define EXPRESSION_EVALUATOR_H

#include "ILoggable.h"
#include <cstddef>
#include <string>
#include <fstream>
#include <iostream>

// ����������� ������� ����� ��� ���������� ���������
class ExpressionEvaluator : public ILoggable {
protected:
    double* operands;        // ������ ���������
    size_t operandsCount;    // ���������� ���������

public:
    // ����������� �� ��������� - �������� ������ ��� 20 ���������
    ExpressionEvaluator() : operandsCount(20) {
        operands = new double[operandsCount]();
    }

    // ����������� � ���������� - �������� ������ ��� n ���������
    explicit ExpressionEvaluator(size_t n) : operandsCount(n) {
        operands = new double[operandsCount]();
    }

    // ����������� ���������� ��� ������������ ������
    virtual ~ExpressionEvaluator() {
        delete[] operands;
    }

    // ����� ����������� ������� ��� ���������� ���������� ���������
    virtual double calculate() = 0;

    // ��������� �������� ������ ��������
    void setOperand(size_t pos, double value) {
        if (pos < operandsCount) {
            operands[pos] = value;
        }
    }

    // ��������� �������� ������ ���������
    void setOperands(double ops[], size_t n) {
        size_t count = std::min(n, operandsCount);
        for (size_t i = 0; i < count; ++i) {
            operands[i] = ops[i];
        }
    }

    // ������ ��������� � ����
    void logToFile(const std::string& filename) override {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << getExpressionString() << " < Total " << operandsCount << " > " << std::endl;
            file << "< Result " << calculate() << " >" << std::endl;
            file.close();
        }
    }

    // ����� ��������� �� �����
    void logToScreen() override {
        std::cout << getExpressionString() << " < Total " << operandsCount << " > " << std::endl;
        std::cout << "< Result " << calculate() << " >" << std::endl;
    }

protected:
    // ����������� ������� ��� ��������� ���������� ������������� ���������
    virtual std::string getExpressionString() const = 0;
};

#endif