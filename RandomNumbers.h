#pragma once
#include <random>

class RandomNumbers {

    RandomNumbers() {};
public:

      float generateRandomNumber(float rangeStart, float rangeEnd);

    static RandomNumbers& getInstance();
    RandomNumbers(RandomNumbers const&) = delete;
    void operator=(RandomNumbers const&) = delete;
};