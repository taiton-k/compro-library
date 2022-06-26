#include <cstdint>
#include <cassert>
#include <vector>



namespace compro {

        class SieveOfEratosthenes {

        public:
                SieveOfEratosthenes (std::size_t n) noexcept;

                bool isPrime (std::size_t x) noexcept;

                template<class OutputIterator>
                void makeList (OutputIterator result) noexcept;

        private:
                std::vector<bool> sieve_;
        };

        constexpr bool isPrime (std::int64_t x) noexcept;
}



namespace compro {

        SieveOfEratosthenes::SieveOfEratosthenes (std::size_t n) noexcept {
                sieve_.resize(n + 1);

                sieve_[0] = sieve_[1] = true;

                for (std::size_t i = 2; i * i < n; ++i) {
                        if (sieve_[i] == true) {
                                continue;
                        }

                        for (std::size_t j = 2; j * i <= n; ++j) {
                                sieve_[j * i] = true;
                        }
                }
        }

        bool SieveOfEratosthenes::isPrime (std::size_t x) noexcept {
                assert(x < sieve_.size());

                if (x < 0) {
                        return false;
                }
                else {
                        return not sieve_[x];
                }
        }

        template<class OutputIterator>
        void SieveOfEratosthenes::makeList (OutputIterator result) noexcept {
                for (std::size_t i = 2; i < sieve_.size(); ++i) {
                        if (isPrime(i)) {
                                *result = i;
                                ++result;
                        }
                }
        }


        constexpr bool isPrime (std::int64_t x) noexcept {
                if (x < 2) {
                        return false;
                }

                for (int i = 2; i * i <= x; ++i) {
                        if (x % i == 0) {
                                return false;
                        }
                }

                return true;
        }
}