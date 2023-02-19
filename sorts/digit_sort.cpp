#include "sorts.h"

int digit(int number, int index) {
    return (number & (0xFF << (index * 8))) >> (index * 8);
}

void digit_sort(std::vector<int> &vector) {
    int k = 256, m = 4;
    std::vector<int> c(256, 0);
    std::vector<int> b(vector.size());
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < k; ++j) {
            c[j] = 0;
        }
        for (int j = 0; j < vector.size(); ++j) {
            int d = digit(vector[j], i);
            ++c[d];
        }
        int count = 0;
        for (int j = 0; j < k; ++j) {
            int tmp = c[j];
            c[j] = count;
            count += tmp;
        }
        for (int j = 0; j < vector.size(); ++j) {
            int d = digit(vector[j], i);
            b[c[d]] = vector[j];
            ++c[d];
        }
        vector = b;
    }
}

size_t digit_sort_operations(std::vector<int> &vector) {
    size_t operations = 0;
    int k = 256, m = 4;
    operations += 3 + 3;
    std::vector<int> c(256, 0);
    operations += c.size() * 2;
    std::vector<int> b(vector.size());
    operations += b.size() * 2;

    operations += 3;
    for (int i = 0; i < m; ++i) {
        operations += 5;

        operations += 3;
        for (int j = 0; j < k; ++j) {
            operations += 5;
            c[j] = 0;
            operations += 3;
        }
        operations += 3;
        for (int j = 0; j < vector.size(); ++j) {
            operations += 5;
            int d = digit(vector[j], i);
            operations += 2 + 3 + 13;
            ++c[d];
            operations += 3;
        }
        int count = 0;
        operations += 3;
        operations += 3;
        for (int j = 0; j < k; ++j) {
            operations += 5;
            int tmp = c[j];
            operations += 4;
            c[j] = count;
            operations += 4;
            count += tmp;
            operations += 3;
        }
        operations += 2;
        for (int j = 0; j < vector.size(); ++j) {
            operations += 5;
            int d = digit(vector[j], i);
            operations += 2 + 3 + 13;
            b[c[d]] = vector[j];
            operations += 6;
            ++c[d];
            operations += 3;
        }
        vector = b;
        operations += b.size() * 2;
    }
    return operations;
}