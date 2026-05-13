#include <iostream>
#include <unordered_map>


unsigned long fib(uint termNum, std::unordered_map<uint, unsigned long>& fibNums) {
    // if function result already exists
    auto iterator = fibNums.find(termNum);
    if (iterator != fibNums.end()) {
        return iterator->second;
    } else {
        // if not in map then populate the map with result to reduce compute cost
        unsigned long result = fib(termNum - 2, fibNums) + fib(termNum - 1, fibNums);
        fibNums.insert({termNum, result});
        return result;
    }
}

bool isEven(uint num) {
    if ((num & 1) == 0) {
        return true;
    }
    return false;
}

int main() {
    std::unordered_map<uint, unsigned long> fibNums;
    fibNums.insert({{1, 1}, {2, 2}});

    // calculate fib until 4 million result to populate map
    uint count = 1;
    while (fib(count, fibNums) < 4'000'000) {
        count++;
    }

    // sum up all even values
    unsigned long sum = 0;
    for (auto pair : fibNums) {
        unsigned long val = pair.second;
        if (isEven(val)) {
            sum += val;
        }
    }

    std::cout << sum << "\n";

    return 0;
}

