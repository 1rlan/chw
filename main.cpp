#include "sorts_run/sorts_run.h"

// Вся инорфмация о работае хранится в файле report.md !

int main() {
    // Выставление сида генерации
    srand((unsigned) time(nullptr));
    // Класс прогона
    auto running = Running();
    // Прогоны
    running.run_for_time("small");
    running.run_for_time("big");
    running.run_for_operations("small");
    running.run_for_operations("big");
    return 0;
}


