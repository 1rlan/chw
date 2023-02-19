#include "sorts.h"

void insertion_sort(std::vector<int> &vector) {
    for (int i = 1; i < vector.size(); ++i) {
        size_t j = i;
        while (j > 0 && vector[j - 1] > vector[j]) {
            std::swap(vector[j - 1], vector[j]);
            --j;
        }
    }
}

size_t insertion_sort_operations(std::vector<int> &vector) {
    size_t operations = 0;
    operations += 3;
    for (int i = 1; i < vector.size(); ++i) {
        operations += 5;
        size_t j = i;
        operations += 3;
        while (j > 0 && vector[j - 1] > vector[j]) {
            operations += 3 + 1 + 6;
            std::swap(vector[j - 1], vector[j]);
            operations += 3;
            --j;
            operations += 2;
        }
    }
    return operations;
}