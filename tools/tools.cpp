#include "tools.h"

// Проверка на сортированность.
// Если массив НЕ отсортирован, то вызывается иксключение.
void is_sorted(std::vector<int> &vector) {
    for (int i = 0; i < vector.size() - 1; ++i) {
        if (vector[i] > vector[i + 1]) {
            throw std::invalid_argument("Array is not sorted");
        }
    }
    vector.clear();
}

// Вывод массива в консоль.
std::ostream& operator <<(std::ostream &os, const std::vector<int>& vector) {
    for (int i = 0; i < vector.size(); ++i) {
        os << vector[i] << ' ';
    }
    return os;
}