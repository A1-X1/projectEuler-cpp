#include <iostream>
#include <vector>

uint64_t asciiToInt(uint32_t asciiValue) {
    return asciiValue - 48;
}

uint8_t digitAtIndex(uint64_t index, std::string numberAsString) {
    uint8_t digitValue = asciiToInt(numberAsString[index]);
    return digitValue;
}

// implement a 'sliding window' solution going along the large number
uint64_t largestProductOfNConsecutiveDigits(uint32_t digits, std::string numberAsString) {
    uint64_t largestSeenProduct = 0;
    uint length = numberAsString.length();



    for (uint32_t startingPosition = 0; startingPosition < (length - digits); startingPosition++) {
        uint64_t product = 1;
        for (int i = startingPosition; i < startingPosition + digits; i++) {
            product *= digitAtIndex(i, numberAsString);
        }
        if (product > largestSeenProduct) {
            largestSeenProduct = product;
        }
    }

    return largestSeenProduct;
}

int main() {
    std::string largeNumAsStr = "731671765313306249192251196795833195285320880551112540698747158523863050715693290963295227443043557668966489504452445231617318564030987111217223831136222989342338030813533627661428280644448664523874930358907296290491560440772390713810515859307960866701724271218871167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
    uint64_t result = largestProductOfNConsecutiveDigits(13, largeNumAsStr);

    std::cout << result << "\n";

    return 0;
}


