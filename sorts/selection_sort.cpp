#include "sorts.h"

void selection_sort(std::vector<int> &vector) {
    for (size_t i = 0; i < vector.size() - 1; ++i) {
        size_t minPos = i;
        for (size_t j = i + 1; j < vector.size(); ++j) {
            if (vector[j] < vector[minPos]) {
                minPos = j;
            }
        }
        std::swap(vector[minPos], vector[i]);
    }
}

size_t selection_sort_operations(std::vector<int> &vector) {
    size_t operations = 0;
    operations += 3;
    for (size_t i = 0; i < vector.size() - 1; ++i) {
        operations += 6;
        size_t minPos = i;
        operations += 3;
        operations += 4;
        for (size_t j = i + 1; j < vector.size(); ++j) {
            operations += 5;
            if (vector[j] < vector[minPos]) {
                minPos = j;
                operations += 3;
            }
            operations += 5;
        }
        std::swap(vector[minPos], vector[i]);
        operations += 3;
    }
    return operations;
}