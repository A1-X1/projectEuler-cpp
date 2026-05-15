#include <iostream>
#include <array>
#include <optional>

bool isInteger(double num) {
    if (floor(num) == num) {
        return true;
    }
    return false;
}

bool isTargetTriplet(uint32_t a, uint32_t b, uint32_t c, uint32_t targetSum) {
    if ( (a < b) && ( b < c) && ((a+b+c) == targetSum) ) {
        return true;
    }
    return false;
}

std::array<uint32_t, 3> findPythagoreanTriplet(uint64_t maxNum, uint32_t targetSum) {
    std::array<uint32_t, 3> pythagoreanTriplet{0, 0, 0};
    // O(n^2) time complexity
    for (int a = 0; a < maxNum; a++) {
        // quick optimisation to prevent wasted compute
        if (pow(a, 2) > pow(targetSum, 2)) {
            break;
        }
        for (int b = 0; b < maxNum; b++) {
            if (pow(b, 2) > pow(targetSum, 2)) {
                break;
            }
            double sumOfSquares = pow(a, 2) + pow(b, 2);
            if (isInteger(sqrt(sumOfSquares))) {
                uint32_t c = sqrt(sumOfSquares);
                if (isTargetTriplet(a, b, c, targetSum)){
                    pythagoreanTriplet[0] = a;
                    pythagoreanTriplet[1] = b;
                    pythagoreanTriplet[2] = c;
                    return pythagoreanTriplet;
                }
            }
        }
    }
    return pythagoreanTriplet;
}


int main() {

    std::array<uint32_t, 3> targetTriplet = findPythagoreanTriplet(100000, 1000);
    uint64_t result = targetTriplet[0] * targetTriplet[1] * targetTriplet[2];

    std::cout << result << "\n";

    return 0;
}


