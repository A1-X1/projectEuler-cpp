#include <iostream>
#include <vector>
#include <unordered_map>
#include <valarray>

void multiplyNDigitNums(const uint digits, std::vector<uint32_t>& allProducts) {
    uint32_t startNum = std::pow(10, (digits-1));
    uint32_t endNum = std::pow(10, (digits));

    for (int num1 = startNum; num1 < endNum; num1++) {
        for (int num2 = startNum; num2 < endNum; num2++) {
            allProducts.push_back(num1*num2);
        }
    }

}

bool isPalindrome(uint32_t num) {
    std::string reversed = std::to_string(num);
    std::string original = std::to_string(num);

    std::reverse(std::begin(original), std::end(original));

    if (reversed == original) {
        return true;
    }

    return false;

}

uint64_t findLargestPalindrome(const uint digits, std::vector<uint32_t>& allProducts) {
    multiplyNDigitNums(digits, allProducts);
    uint64_t largestSeenPalindrome = 0;

    for (auto value: allProducts) {
        if (isPalindrome(value) && (value > largestSeenPalindrome)) {
            largestSeenPalindrome = value;
        }
    }

    return largestSeenPalindrome;
}

int main() {
    uint32_t digits = 3;

    // dont need to store pairs of numbers that made the result, just the value itself thus key is irrelevant
    std::vector<uint32_t> allProducts;

    uint64_t largestPalindrome = findLargestPalindrome(digits, allProducts);

    std::cout << largestPalindrome;





    return 0;
}


