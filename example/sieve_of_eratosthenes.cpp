#include <iostream>
#include <vector>
#include "compro/numeric.hpp"



int main () {

        compro::SieveOfEratosthenes sieve(100);

        std::cout << sieve.size() << std::endl; // 100

        std::cout << std::boolalpha <<
                sieve.isPrime(2) << std::endl << // true
                sieve.isPrime(7) << std::endl << // true
                sieve.isPrime(4) << std::endl << // false
                sieve.isPrime(9) << std::endl;   // false

        std::vector<int> primes;
        sieve.makeList(std::back_inserter(primes));

        for (int prime : primes) {
                std::cout << prime << ' ';
        }
        std::cout << std::endl;
}
