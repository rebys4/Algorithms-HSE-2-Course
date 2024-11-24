#ifndef ARRAY_GENERATOR_H
#define ARRAY_GENERATOR_H

#include <vector>
#include <random>
#include <algorithm>
#include <iostream>

class ArrayGenerator {
    private:
        std::vector<int> array;
        std::mt19937 rng;
        
    public:
        ArrayGenerator() {
            std::random_device rd;
            rng = std::mt19937(rd());
            std::uniform_int_distribution<int> dist(0, 6000);

            array.resize(10000);
            for (int& num : array) {
                num = dist(rng);
            }
        }

        std::vector<int> getRandomArray(int size) {
            return std::vector<int>(array.begin(), array.begin() + size);
        }

        std::vector<int> getReversedArray(int size) {
            std::vector<int> array = getRandomArray(size);
            std::sort(array.rbegin(), array.rend());
            return array;
        }

        std::vector<int> getNearlySortedArray(int size, int swaps = 10) {
            std::vector<int> array = getRandomArray(size);
            std::sort(array.begin(), array.end());

            for (int i = 0; i < swaps; ++i) {
                int idx1 = rng() % size;
                int idx2 = rng() % size;
                std::swap(array[idx1], array[idx2]);
            }

            return array;
        }

};

#endif // ARRAY_GENERATOR_H
