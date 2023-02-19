#include "sorts_run.h"

// Генерация эталонных векторов
Running::Running() {
    vectors = {
        generateRandomVector(4100, 5),
        generateRandomVector(4100, 4000),
        generateAlmostSortedVector(4100),
        generateReversedVector(4100)
    };
}

// Прогон и запись в поток данных о времени работы сортировок
void Running::run_for_time(std::string size_string) {
    stream.open("time_" + size_string + ".csv");
    write_data(stream);

    for (auto size : (size_string == "small" ? small_sizes : big_sizes)) {
        stream << size << ";";
        for (int i = 0; i < sorts.size(); ++i) {
            for (int j = 0; j < vectors.size(); ++j) {
                size_t time = 0;
                for (int k = 0; k < 10; ++k) {
                    std::copy(vectors[j].begin(), vectors[j].begin() + size,  std::back_inserter(copy));
                    time += count_time(sorts[i], copy);
                    is_sorted(copy);
                }
                stream << time / 10 << ";";
            }
        }
        stream << "\n";
    }
    stream.close();
}


// Прогон и запись в поток данных о кол-ве операций работы сортировок
void Running::run_for_operations(std::string size_string) {
    stream.open("operations_" + size_string + ".csv");
    write_data(stream);

    for (auto size : (size_string == "small" ? small_sizes : big_sizes)) {
        stream << size << ";";
        for (int i = 0; i < sorts.size(); ++i) {
            for (int j = 0; j < vectors.size(); ++j) {
                size_t operations = 0;
                for (int k = 0; k < 10; ++k) {
                    std::copy(vectors[j].begin(), vectors[j].begin() + size,  std::back_inserter(copy));
                    operations += sorts_operations[i](copy);
                    is_sorted(copy);
                }
                stream << operations / 10 << ";";
            }
        }
        stream << "\n";
    }
    stream.close();
}

// Закрытие потока
Running::~Running() {
    stream.close();
}

// Подсчет времени работы сортировки в НС
size_t Running::count_time(void (*func)(std::vector<int> &), std::vector<int> &vector) {
    auto start = std::chrono::high_resolution_clock::now();
    func(vector);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    return std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
}

// Запись "шапки" .csv файла.
void Running::write_data(std::ofstream &stream) {
    stream << "Array Size" << ";";
    for (int i = 0; i < 13; ++i) {
        stream << sort_string[i] + " " + "0-5" << ";";
        stream << sort_string[i] + " " + "0-4000" << ";";
        stream << sort_string[i] + " " + "almost" << ";";
        stream << sort_string[i] + " " + "reversed" << ";";
    }
    stream << "\n";
}