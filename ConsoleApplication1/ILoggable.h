#ifndef ILOGGABLE_H
#define ILOGGABLE_H

#include <string>

// Интерфейс для реализации функционала логирования
class ILoggable {
public:
    // Вывод информации на экран
    virtual void logToScreen() = 0;
    // Запись информации в файл
    virtual void logToFile(const std::string& filename) = 0;
    virtual ~ILoggable() = default;
};

#endif