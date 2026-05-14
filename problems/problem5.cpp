#include <iostream>
#include <vector>
#include <valarray>

uint64_t factorial(uint32_t num) {
    if (num == 0) {
        return 1;
    }
    return num * factorial(num - 1);
}

uint64_t findEvenlyDivisible(uint32_t lower, uint32_t upper) {
    std::vector<uint32_t> allNumbers;
    uint64_t smallestEvenlyDivisibleNum = 0;

    // first work out the largest number it can be, by having every number as a factor, thus multiply 1 to n to get max
    uint64_t maxNum = 1;
    for (uint32_t num = lower; num < upper + 1; num++) {
        maxNum *= num;
        allNumbers.push_back(num);
    }

    // O(n^2) nested for loop
    // basic optimisation, to save time, it must be a multiple of the largest number already (upper)
    for (uint32_t num = 0; num < maxNum; num += upper ) {
        // count to see if all the numbers were searched
        uint maxCount = (upper - lower) + 1;
        uint count = 0;
        for (uint32_t numberToDivide: allNumbers) {
            if ((num % numberToDivide) == 0) {
                smallestEvenlyDivisibleNum = num;
                count++;
            } else {
                // if not found reset the number
                smallestEvenlyDivisibleNum = 0;
                break;
            }
        }
        if ((count == maxCount) && smallestEvenlyDivisibleNum != 0) {
            return smallestEvenlyDivisibleNum;
        }
    }




}


int main() {
    uint64_t result = findEvenlyDivisible(1, 20);

    std::cout << result << "\n";

    return 0;
}


