#include <iostream>
#include <vector>

uint64_t sumOfFirstNSquares(uint32_t num) {
    std::vector<uint64_t> numbers;

    for (int i = 1; i < (num + 1); i++) {
        numbers.push_back(i);
    }

    uint64_t sum = 0;

    for (uint64_t number: numbers) {
        sum += pow(number, 2);
    }

    return sum;
}

uint64_t squareOfFirstNNumbersAdded(uint32_t num) {
    std::vector<uint64_t> numbers;
    uint64_t sumOfNumbers = 0;

    for (int i = 1; i < (num + 1); i++) {
        sumOfNumbers += i;
    }

    uint64_t returnValue = pow(sumOfNumbers, 2);

    return returnValue;
}

int main() {
    uint64_t result = squareOfFirstNNumbersAdded(100) - sumOfFirstNSquares(100);

    std::cout << result << "\n";

    return 0;
}


