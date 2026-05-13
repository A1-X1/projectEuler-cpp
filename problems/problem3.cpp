#include <iostream>
#include <vector>

uint64_t findLargestPrimeFactor (uint64_t target) {
    std::vector<uint64_t> factors;
    uint64_t currentNum = target;

    // check all factors of 2
    while ( (currentNum % 2) == 0 ) {
        factors.push_back(2);
        currentNum /= 2;
    }

    // check all odd numbers
    for (uint64_t num = 3; num < target; num += 2) {
        if (currentNum == 1) {
            break;
        }
        while ( (currentNum % num) == 0 ) {
            factors.push_back(num);
            currentNum /= num;
        }
    }

    // logically, the last num will be greatest factor
    return factors.back();

}

int main() {
    uint64_t target = 600'851'475'143;

    uint result = findLargestPrimeFactor(target);

    std::cout << result;


    return 0;
}


