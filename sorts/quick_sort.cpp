#include "sorts.h"

int part(std::vector<int> &vector, int start, int end) {
    int pivot = vector[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (vector[i] <= pivot)
            count++;
    }
    int index = start + count;
    std::swap(vector[index], vector[start]);
    int i = start, j = end;
    while (i < index && j > index) {
        while (vector[i] <= pivot) {
            i++;
        }
        while (vector[j] > pivot) {
            j--;
        }
        if (i < index && j > index) {
            std::swap(vector[i++], vector[j--]);
        }
    }
    return index;
}

void quick_sort(std::vector<int> &vector, int left, int right) {
    if (left >= right) {
        return;
    }
    int p = part(vector, left, right);
    quick_sort(vector, left, p - 1);
    quick_sort(vector, p + 1, right);
}


void quick_sort(std::vector<int> &vector) {
    quick_sort(vector, 0, vector.size() - 1);
}

std::pair<size_t, int> part_operations(std::vector<int> &vector, int start, int end) {
    size_t operations = 0;
    int pivot = vector[start];
    operations += 4;
    int count = 0;
    operations += 3;
    operations += 3;
    for (int i = start + 1; i <= end; i++) {
        operations += 5;
        if (vector[i] <= pivot) {
            operations += 4;
            ++count;
            operations += 2;
        }
    }
    int index = start + count;
    operations += 5;
    std::swap(vector[index], vector[start]);
    operations += 3;
    int i = start, j = end;
    operations += 6;
    while (i < index && j > index) {
        operations += 5;
        while (vector[i] <= pivot) {
            operations += 4;
            i++;
            operations += 2;
        }
        while (vector[j] > pivot) {
            operations += 4;
            j--;
            operations += 2;
        }
        if (i < index && j > index) {
            std::swap(vector[i++], vector[j--]);
            operations += 3;
        }
        operations += 5;
    }
    operations += 3;
    return {operations, index};
}

size_t quick_sort_operations(std::vector<int> &vector, int left, int right) {
    size_t operations = 0;
    operations += 3;
    if (left >= right) {
        return operations + 1;
    }
    auto p = part_operations(vector, left, right);
    operations += p.first;
    return operations + quick_sort_operations(vector, left, p.second - 1) + quick_sort_operations(vector, p.second + 1, right) + 8 + 3;
}

size_t quick_sort_operations(std::vector<int> &vector) {
    return quick_sort_operations(vector, 0, vector.size() - 1);
}
