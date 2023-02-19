#ifndef CHW_SORTS_RUN_H
#define CHW_SORTS_RUN_H

#include <unordered_map>
#include <iostream>
#include <fstream>
#include <vector>
#include "../generations/generators.h"
#include "../sorts/sorts.h"
#include "../tools/tools.h"

struct Running {
    //  Поток вывода в .csv файл.
    std::ofstream stream;

    // Временный вектор, в которй копируется эталонный массив
    std::vector<int> copy;
    // Эталонные массивы
    std::vector<std::vector<int>> vectors;

    // Размеры для двух тестов
    std::vector<int> small_sizes { 50, 100, 150, 200, 250, 300 };
    std::vector<int> big_sizes {
        100, 200, 300, 400, 500,
        600, 700, 800, 900, 1000,
        1100, 1200, 1300, 1400, 1500,
        1600, 1700, 1800, 1900, 2000,
        2100, 2200, 2300, 2400, 2500,
        2600, 2700, 2800, 2900, 3000,
        3100, 3200, 3300, 3400, 3500,
        3600, 3700, 3800, 3900, 4000,
        4100
    };

    // Название массива
    std::unordered_map<int, std::string> sort_string {
            {0, "Selection"},
            {1, "Bubble"},
            {2, "Bubble_1"},
            {3, "Bubble_1+2"},
            {4, "Insertions"},
            {5, "Binary Insertions"},
            {6, "Counting"},
            {7, "Digit"},
            {8, "Merge"},
            {9, "Quick"},
            {10, "Heap"},
            {11, "Shell Ciura"},
            {12, "Shell"},
    };

    // Указатели на функции сортировок
    std::vector<void (*)(std::vector<int> &)> sorts {
            selection_sort,
            bubble_sort,
            bubble_sort_1,
            bubble_sort_1_2,
            insertion_sort,
            insertion_binary_sort,
            counting_sort,
            digit_sort,
            merge_sort,
            quick_sort,
            heap_sort,
            shell_ciura_sort,
            shell_sort
    };

    // Указалтели на функции сортировок с операциями
    std::vector<size_t (*)(std::vector<int> &)> sorts_operations = {
            selection_sort_operations,
            bubble_sort_operations,
            bubble_sort_1_operations,
            bubble_sort_1_2_operations,
            insertion_sort_operations,
            insertion_binary_sort_operations,
            counting_sort_operations,
            digit_sort_operations,
            merge_sort_operations,
            quick_sort_operations,
            heap_sort_operations,
            shell_ciura_sort_operations,
            shell_sort_operations
    };

    Running();
    ~Running();
    void write_data(std::ofstream &stream);
    void run_for_time(std::string size_string);
    void run_for_operations(std::string size_string);
    size_t count_time(void (*func)(std::vector<int> &), std::vector<int> &vector);
};

#endif
