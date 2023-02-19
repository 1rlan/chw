#include "sorts.h"

void sift_down(std::vector<int> &vector, int i, size_t heapSize) {
    while (2 * i + 1 < heapSize) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
        if (right < heapSize && vector[left] < vector[right]) {
            j = right;
        }
        if (vector[j] < vector[i] || !((vector[i] < vector[j]) || (vector[j] < vector[i]))) {
            break;
        }
        std::swap(vector[i], vector[j]);
        i = j;
    }
}

void build_heap(std::vector<int> &vector) {
    for (int i = static_cast<int>(vector.size() / 2); i > -1; --i) {
        sift_down(vector, i, vector.size());
    }
}

void heap_sort(std::vector<int> &vector) {
    build_heap(vector);
    size_t heapSize = vector.size();
    for (int i = 0; i < vector.size(); ++i) {
        std::swap(vector[0], vector[vector.size() - 1 - i]);
        --heapSize;
        sift_down(vector, 0, heapSize);
    }
}

size_t sift_down_operations(std::vector<int> &vector, int i, size_t heapSize) {
    size_t operations = 0;
    while (2 * i + 1 < heapSize) {
        operations += 7;
        int left = 2 * i + 1;
        operations += 5;
        int right = 2 * i + 2;
        operations += 5;
        int j = left;
        operations += 3;
        if (right < heapSize && vector[left] < vector[right]) {
            j = right;
            operations += 3;
        }
        operations += 12;
        if (vector[j] < vector[i] || !((vector[i] < vector[j]) || (vector[j] < vector[i]))) {
            break;
        }
        std::swap(vector[i], vector[j]);
        operations += 5;
        i = j;
        operations += 3;
    }
    return operations;
}

size_t build_heap_operations(std::vector<int> &vector) {
    size_t opertaions = 0;
    opertaions += 5;
    for (int i = static_cast<int>(vector.size() / 2); i > -1; --i) {
        opertaions += 5;
        opertaions += sift_down_operations(vector, i, vector.size()) + 4;
    }
    return opertaions;
}

size_t heap_sort_operations(std::vector<int> &vector) {
    size_t operations = build_heap_operations(vector) + 1;
    size_t heapSize = vector.size();
    operations += 3;
    for (int i = 0; i < vector.size(); ++i) {
        operations += 5;
        std::swap(vector[0], vector[vector.size() - 1 - i]);
        operations += 3 + 6;
        --heapSize;
        operations += 2;
        operations += sift_down_operations(vector, 0, heapSize) + 3;
    }
    return operations;
}