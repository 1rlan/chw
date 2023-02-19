#include "sorts.h"

size_t bubble_sort_operations(std::vector<int> &vector) {
    size_t operations = 3;
    for (size_t i = 0; i < vector.size() - 1; ++i) {
        operations += 6;
        operations += 2;
        for (size_t j = 0; j < vector.size() - i - 1; ++j) {
            operations += 9;
            if (vector[j + 1] < vector[j]) {
                std::swap(vector[j], vector[j + 1]);
                operations += 3;
            }
            operations += 3;
        }
    }
    return operations;
}

void bubble_sort(std::vector<int> &vector) {
    for (size_t i = 0; i < vector.size() - 1; ++i) {
        for (size_t j = 0; j < vector.size() - i - 1; ++j) {
            if (vector[j + 1] < vector[j]) {
                std::swap(vector[j], vector[j + 1]);
            }
        }
    }
}
