#include "sorts.h"

void bubble_sort_1(std::vector<int> &vector) {
    size_t i = 0;
    bool t = true;
    while (t) {
        t = false;
        for (size_t j = 0; j < vector.size() - i - 1; ++j) {
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
                t = true;
            }
        }
        ++i;
    }
}

size_t bubble_sort_1_operations(std::vector<int> &vector) {
    size_t operations = 0;
    size_t i = 0;
    operations += 3;
    bool t = true;
    operations += 3;
    while (t) {
        operations += 2;
        t = false;
        operations += 3;
        operations += 3;
        for (size_t j = 0; j < vector.size() - i - 1; ++j) {
            operations += 5 + 2;
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
                operations += 3;
                t = true;
                operations += 3;
            }
            operations += 5;
        }
        ++i;
        operations += 2;
    }
    return operations;
}