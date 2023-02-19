#include "sorts.h"

void shell_sort(std::vector<int> &vector) {
    for (int s = vector.size(); s > 0; s /= 2) {
        for (int i = s; i < vector.size(); ++i) {
            for (int j = i - s; j >= 0 && vector[j] > vector[j + s]; j -= s) {
                std::swap(vector[j], vector[j + s]);
            }
        }
    }
}

size_t shell_sort_operations(std::vector<int> &vector) {
    size_t operations = 0;
    operations += 3;
    for (int s = vector.size(); s > 0; s /= 2) {
        operations += 3 + 3;
        operations += 3;
        for (int i = s; i < vector.size(); ++i) {
            operations += 3 + 3 + 2;
            operations += 3;
            for (int j = i - s; j >= 0 && vector[j] > vector[j + s]; j -= s) {
                operations += 15;
                std::swap(vector[j], vector[j + s]);
                operations += 3;
            }
        }
    }
    return operations;
}