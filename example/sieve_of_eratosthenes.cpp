#include <iostream>
#include <vector>
#include "compro/numeric.hpp"



int main () {

        compro::SieveOfEratosthenes sieve(100);

        std::vector<int> primes;
        sieve.makeList(std::back_inserter(primes));

        for (int prime : primes) {
                std::cout << prime << ' ';
        }
}
