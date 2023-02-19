#include "generators.h"

// Генерация ранломного массива с заданным максимальным значением и длинной
std::vector<int> generateRandomVector(size_t size, int max_digit) {
    ++max_digit;
    std::vector<int> vector(size);
    for (int i = 0; i < vector.size(); ++i) {
        vector[i] = rand() % max_digit;
    }
    return vector;
}

// Генерация почти сортированного массива
// В каждых 50 элементах поменяны три пары чисел
std::vector<int> generateAlmostSortedVector(size_t size) {
    int tmp = 1;
    std::vector<int> vector(size);
    generate(vector.begin(), vector.end(), [&tmp] { return tmp++;});
    for (int i = 0; i < vector.size(); i += 50) {
        for (int j = i; j < i + 6; j += 2) {
            std::swap(vector[j], vector[j + 1]);
        }
    }
    return vector;
}

// Генерация переврнутого массива
std::vector<int> generateReversedVector(size_t size) {
    std::vector<int> vector(size);
    generate(vector.begin(), vector.end(), [&size] { return size--;});
    return vector;
}



