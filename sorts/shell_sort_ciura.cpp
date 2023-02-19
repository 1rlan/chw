#include "sorts.h"

void shell_ciura_sort(std::vector<int> &vector) {
    std::vector<int> seq {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    for (auto s: seq) {
        for (int i = s; i < vector.size(); ++i) {
            for (int j = i - s; j >= 0 && vector[j] > vector[j + s]; j -= s) {
                std::swap(vector[j], vector[j + s]);
            }
        }
    }
}

size_t shell_ciura_sort_operations(std::vector<int> &vector) {
    size_t operations = 0;
    std::vector<int> seq {1, 4, 10, 23, 57, 132, 301, 701, 1750};
    operations += seq.size() * 3;
    operations += 3;
    for (auto s: seq) {
        operations += 5;
        operations += 3;
        for (int i = s; i < vector.size(); ++i) {
            operations += 5;
            operations += 4;
            for (int j = i - s; j >= 0 && vector[j] > vector[j + s]; j -= s) {
                operations += 13;
                std::swap(vector[j], vector[j + s]);
                operations += 3;
            }
        }
    }
    return operations;
}