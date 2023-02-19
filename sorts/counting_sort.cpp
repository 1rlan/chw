#include "sorts.h"

void counting_sort(std::vector<int> &vector) {
    std::vector<int> add(4200);
    std::vector<int> ans(vector.size());
    for (size_t i = 0; i < vector.size(); ++i) {
        ++add[vector[i]];
    }
    for (int i = 1; i < 4200; ++i) {
        add[i] += add[i - 1];
    }

    for (int i = vector.size() - 1; i > -1; --i) {
        --add[vector[i]];
        ans[add[vector[i]]] = vector[i];
    }
    vector = ans;
}

size_t counting_sort_operations(std::vector<int> &vector) {
    size_t operations = 0;
    std::vector<int> add(4200);
    operations += 4200 * 2;
    std::vector<int> ans(vector.size());
    operations += vector.size() * 2;
    operations += 3;
    for (size_t i = 0; i < vector.size(); ++i) {
        operations += 4;
        ++add[vector[i]];
        operations += 3 + 1;
    }
    operations += 3;
    for (int i = 1; i < 4200; ++i) {
        operations += 3 + 2;
        add[i] += add[i - 1];
        operations += 3 + 3 + 2 + 2;
    }
    operations += 3;
    for (int i = vector.size() - 1; i > -1; --i) {
        operations += 3 + 2;
        --add[vector[i]];
        operations += 3 + 1 + 3 + 2;
        ans[add[vector[i]]] = vector[i];
        operations += 3 + 1 + 1;
    }
    vector = ans;
    operations += vector.size() * 2;
    return operations;
}