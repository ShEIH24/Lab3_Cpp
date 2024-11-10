#ifndef ISHUFFLE_H
#define ISHUFFLE_H

#include <cstddef>

// Интерфейс для реализации функционала перемешивания операндов
class IShuffle {
public:
    // Перемешивание всех операндов
    virtual void shuffle() = 0;
    // Перемешивание двух конкретных операндов
    virtual void shuffle(size_t i, size_t j) = 0;
    virtual ~IShuffle() = default;
};

#endif