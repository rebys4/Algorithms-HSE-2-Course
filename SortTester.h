#ifndef SORT_TESTER_H
#define SORT_TESTER_H

#include <chrono>
#include "ArrayGenerator.h"
#include "Algorithms.h"

class SortTester {
    public:
        long long measureMergeSort(std::vector<int> array) {
            auto start = std::chrono::high_resolution_clock::now();
            mergeSort(array, 0, array.size() - 1);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            long long msec = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
            return msec;
        }

        long long measureHybridSort(std::vector<int> array, int threshold) {
            auto start = std::chrono::high_resolution_clock::now();
            hybridMergeSort(array, 0, array.size() - 1, threshold);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            long long msec = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
            return msec;
        }
};

#endif // SORT_TESTER_H