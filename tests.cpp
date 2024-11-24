#include <iostream>
#include <vector>
#include <fstream>
#include "SortTester.h"

int main() {
    ArrayGenerator generator;
    SortTester tester;

    std::ofstream results("results(threshold=400).csv");
    results << "Size,Type,MergeSort,HybridSort(Threshold=400)\n";

    for (int size = 500; size <= 10000; size += 100) {
        // Генерация данных
        auto randomArray = generator.getRandomArray(size);
        auto reversedArray = generator.getReversedArray(size);
        auto nearlySortedArray = generator.getNearlySortedArray(size);

        // Замеры времени
        long long timeMergeRandom = tester.measureMergeSort(randomArray);
        long long timeHybridRandom = tester.measureHybridSort(randomArray, 400);

        long long timeMergeReversed = tester.measureMergeSort(reversedArray);
        long long timeHybridReversed = tester.measureHybridSort(reversedArray, 400);

        long long timeMergeNearly = tester.measureMergeSort(nearlySortedArray);
        long long timeHybridNearly = tester.measureHybridSort(nearlySortedArray, 400);

        // Запись результатов
        results << size << ",Random," << timeMergeRandom << "," << timeHybridRandom << "\n";
        results << size << ",Reversed," << timeMergeReversed << "," << timeHybridReversed << "\n";
        results << size << ",NearlySorted," << timeMergeNearly << "," << timeHybridNearly << "\n";
    }

    results.close();
    std::cout << "Результаты сохранены в файл results.csv\n";

    return 0;
}
