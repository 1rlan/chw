#ifndef CHW_SORTS_H
#define CHW_SORTS_H

#include <vector>

void heap_sort(std::vector<int> &vector);
void merge_sort(std::vector<int> &vector);
void quick_sort(std::vector<int> &vector);
void digit_sort(std::vector<int> &vector);
void shell_sort(std::vector<int> &vector);
void bubble_sort(std::vector<int> &vector);
void bubble_sort_1(std::vector<int> &vector);
void counting_sort(std::vector<int> &vector);
void bubble_sort_1(std::vector<int> &vector);
void insertion_sort(std::vector<int> &vector);
void selection_sort(std::vector<int> &vector);
void bubble_sort_1_2(std::vector<int> &vector);
void shell_ciura_sort(std::vector<int> &vector);
void insertion_binary_sort(std::vector<int> &vector);

size_t heap_sort_operations(std::vector<int> &vector);
size_t merge_sort_operations(std::vector<int> &vector);
size_t quick_sort_operations(std::vector<int> &vector);
size_t digit_sort_operations(std::vector<int> &vector);
size_t shell_sort_operations(std::vector<int> &vector);
size_t bubble_sort_operations(std::vector<int> &vector);
size_t bubble_sort_1_operations(std::vector<int> &vector);
size_t counting_sort_operations(std::vector<int> &vector);
size_t bubble_sort_1_operations(std::vector<int> &vector);
size_t insertion_sort_operations(std::vector<int> &vector);
size_t selection_sort_operations(std::vector<int> &vector);
size_t bubble_sort_1_2_operations(std::vector<int> &vector);
size_t shell_ciura_sort_operations(std::vector<int> &vector);
size_t insertion_binary_sort_operations(std::vector<int> &vector);

#endif
