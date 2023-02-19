#include "sorts.h"

void insertion_binary_sort(std::vector<int> &vector) {
    for (int i = 0; i < vector.size(); ++i) {
        int key = vector[i];
        int lo = 0, hi = i - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (key < vector[mid]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        for (int j = i; j > lo + 1; --j) {
            vector[j] = vector[j - 1];
        }
        vector[lo] = key;
    }
}

size_t insertion_binary_sort_operations(std::vector<int> &vector) {
    size_t operations = 0;
    operations += 3;
    for (int i = 0; i < vector.size(); ++i) {
        operations += 5;
        int key = vector[i];
        operations += 4;
        int lo = 0, hi = i - 1;
        operations += 3 + 3 + 1;
        while (lo < hi) {
            operations += 3;
            int mid = lo + (hi - lo) / 2;
            operations += 2 + 3 + 2 + 2;
            if (key < vector[mid]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
            operations += 4 + 3;
        }
        operations += 3;
        for (int j = i; j > lo + 1; --j) {
            operations += 4 + 2;
            vector[j] = vector[j - 1];
            operations += 3 + 2;
        }
        vector[lo] = key;
        operations += 3;
    }
    return operations;
}