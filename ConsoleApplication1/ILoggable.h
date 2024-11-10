#ifndef ILOGGABLE_H
#define ILOGGABLE_H

#include <string>

// ��������� ��� ���������� ����������� �����������
class ILoggable {
public:
    // ����� ���������� �� �����
    virtual void logToScreen() = 0;
    // ������ ���������� � ����
    virtual void logToFile(const std::string& filename) = 0;
    virtual ~ILoggable() = default;
};

#endif