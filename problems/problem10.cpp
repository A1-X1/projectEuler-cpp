#include <iostream>
#include <vector>

std::vector<uint64_t> generatePrimes (uint64_t maximum) {
    // starting with index 0 and 1 as non prime
    std::vector<bool> numbers(maximum + 1);
    for (auto number: numbers) {
        number = true;
    }
    numbers[0] = false;
    numbers[1] = false;

    std::vector<uint64_t> primes;

    // starting with 2, begin to markdown primes
    for (int i = 2; i < sqrt(maximum); i++) {
        // if prime then mark multiples as not prime
        if (numbers[i] == true) {
            // mark multiples as not prime
            for (int j = i*i; j < (maximum + 1); j += i) {
                numbers[j] = false;
            }
        }
    }

    // create a list of primes
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == true) {
            primes.push_back(i);
        }
    }

    return primes;
    
}

uint64_t sumOfPrimesBelowN(uint64_t maximum) {
    std::vector<uint64_t> primes = generatePrimes(maximum);

    uint64_t sum = 0;
    for (uint64_t prime: primes) {
        if (prime > maximum) {
            break;
        }
        sum += prime;
    }

    return sum;
}

int main() {

    uint64_t sumOfPrimes = sumOfPrimesBelowN(2'000'000);

    std::cout << sumOfPrimes;


    return 0;
}


