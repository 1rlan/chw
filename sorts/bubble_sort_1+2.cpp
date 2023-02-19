#include "sorts.h"

void bubble_sort_1_2(std::vector<int> &vector) {
    bool t = true;
    int i = 0, l = vector.size() + 1, l1 = vector.size() - 1;
    while (t) {
        t = false;
        l = l < l1 ? l : l1;
        for (int j = 0; j < l; ++j) {
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
                t = true;
                l1 = j;
            }
        }
        ++i;
    }
}

size_t bubble_sort_1_2_operations(std::vector<int> &vector) {
    size_t operations = 0;
    bool t = true;
    operations += 3;
    int i = 0, l = vector.size() + 1, l1 = vector.size() - 1;
    operations += 3 + 5 + 5;
    while (t) {
        operations += 2;
        t = false;
        operations += 2;
        l = l < l1 ? l : l1;
        operations += 5;
        operations += 3;
        for (int j = 0; j < l; ++j) {
            operations += 5;
            if (vector[j] > vector[j + 1]) {
                std::swap(vector[j], vector[j + 1]);
                operations += 3;
                t = true;
                operations += 3;
                l1 = j;
                operations += 3;
            }
            operations += 6;
        }
        ++i;
        operations += 2;
    }
    return operations;
}