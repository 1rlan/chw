#include "sorts.h"

void merge_part(std::vector<int> &vector, std::vector<int> &add, size_t left, size_t mid, size_t right) {
    size_t tmpLeft = left;
    size_t tmpRight = mid;
    for (size_t k = left; k < right; ++k) {
        if (tmpRight == right || (tmpLeft < mid && vector[tmpLeft] <= vector[tmpRight])) {
            add[k] = vector[tmpLeft];
            ++tmpLeft;
        } else {
            add[k] = vector[tmpRight];
            ++tmpRight;
        }
    }
    for (size_t i = left; i < right; ++i) {
        vector[i] = add[i];
    }
}

void merge_sort(std::vector<int> &vector, std::vector<int> &add, size_t left, size_t right) {
    if (right <= left + 1) return;
    int mid = (left + right) / 2;
    merge_sort(vector, add, left, mid);
    merge_sort(vector, add, mid, right);
    merge_part(vector, add, left, mid, right);
}

void merge_sort(std::vector<int> &vector) {
    std::vector<int> add = std::vector<int>(vector.size());
    merge_sort(vector, add, 0, vector.size());
}




size_t merge_part_operations(std::vector<int> &vector, std::vector<int> &add, size_t left, size_t mid, size_t right) {
    size_t operations = 0;
    size_t tmpLeft = left;
    operations += 3;
    size_t tmpRight = mid;
    operations += 3;
    operations += 3;
    for (size_t k = left; k < right; ++k) {
        operations += 5;
        if (tmpRight == right || (tmpLeft < mid && vector[tmpLeft] <= vector[tmpRight])) {
            add[k] = vector[tmpLeft];
            operations += 5;
            ++tmpLeft;
            operations += 2;
        } else {
            add[k] = vector[tmpRight];
            operations += 5;
            ++tmpRight;
            operations += 2;
        }
        operations += 12;
    }
    operations += 3;
    for (size_t i = left; i < right; ++i) {
        operations += 5;
        vector[i] = add[i];
        operations += 5;
    }
    return operations;
}

size_t merge_sort_operations(std::vector<int> &vector, std::vector<int> &add, size_t left, size_t right) {
    size_t operations = 0;
    if (right <= left + 1) return 5;
    int mid = (left + right) / 2;
    operations += 5;
    operations += merge_sort_operations(vector, add, left, mid) + 4;
    operations += merge_sort_operations(vector, add, mid, right) + 4;
    operations += merge_part_operations(vector, add, left, mid, right) + 4;
    return operations;
}

size_t merge_sort_operations(std::vector<int> &vector) {
    size_t operations = 0;
    std::vector<int> add = std::vector<int>(vector.size());
    operations += vector.size() * 2;
    return operations + merge_sort_operations(vector, add, 0, vector.size());
}