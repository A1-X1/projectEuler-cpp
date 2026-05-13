#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


int main() {

    std::unordered_set<int> seenNumbers;

    int result = 0;

    // append all unique 3 multiples
    for (int threes = 3; threes < 1000; threes += 3) {
        seenNumbers.insert(threes);
    }

    // append all unique 5 multiples (avoids duplicates)
    for (int fives = 5; fives < 1000; fives += 5) {
        seenNumbers.insert(fives);
    }

    // sums all
    for (auto item : seenNumbers) {
        result += item;
    }

    std::cout << result;


    return 0;
}

