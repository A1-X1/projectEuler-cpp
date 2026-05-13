#include <iostream>

unsigned long square(unsigned long num) {
    return num * num;
}

bool isOdd(const uint num) {
    if (num & 1) {
        return true;
    } else {
        return false;
    }

}

bool isOdd2(const uint num) {
    if (num % 2 == 1) {
        return true;
    } else {
        return false;
    }

}

int main() {

    unsigned long result = 0;
    uint32_t maxCount = 368000;

    for (uint32_t i = 1; i < maxCount + 1; i++) {
        unsigned long localRes = square(i);
        if (isOdd(localRes)) {
            result += localRes;
        }
    }

    std::cout << result ;


    return 0;
}

