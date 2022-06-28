#include <cstdint>
#include <cassert>
#include <vector>



namespace compro {

        class SieveOfEratosthenes {

        public:
                SieveOfEratosthenes (std::size_t n) noexcept;

                bool isPrime (std::size_t x) const noexcept;

                template<class OutputIterator>
                void makeList (OutputIterator result) const noexcept;

                std::size_t size () const noexcept;

        private:
                std::vector<bool> sieve_;
        };

        template<typename T>
        constexpr bool isPrime (T n) noexcept;

        template<typename T, class OutputIterator>
        constexpr void enumDivisors (T n, OutputIterator result) noexcept;

        template<typename T, class OutputIterator>
        constexpr void primeFactorize (T n, OutputIterator result) noexcept;
}



namespace compro {

        SieveOfEratosthenes::SieveOfEratosthenes (std::size_t n) noexcept :
                sieve_(n + 1)
        {
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

        bool SieveOfEratosthenes::isPrime (std::size_t x) const noexcept {
                assert(x < sieve_.size());

                if (x < 0) {
                        return false;
                }
                else {
                        return not sieve_[x];
                }
        }

        template<class OutputIterator>
        void SieveOfEratosthenes::makeList (OutputIterator result) const noexcept {
                for (std::size_t i = 2; i < sieve_.size(); ++i) {
                        if (isPrime(i)) {
                                *result = i;
                                ++result;
                        }
                }
        }

        std::size_t SieveOfEratosthenes::size () const noexcept {
                return sieve_.size() - 1;
        }


        template<typename T>
        constexpr bool isPrime (T n) noexcept {
                if (n < 2) {
                        return false;
                }

                for (T i = 2; i * i <= n; ++i) {
                        if (n % i == 0) {
                                return false;
                        }
                }

                return true;
        }

        template<typename T, class OutputIterator>
        constexpr void enumDivisors (T n, OutputIterator result) noexcept {
                for (T i = 1; i * i <= n; ++i) {
                        if (n % i == 0) {
                                *result = i;
                                ++result;

                                if (i != n/i) {
                                        *result = n/i;
                                        ++result;
                                }
                        }
                }
        }

        template<typename T, class OutputIterator>
        constexpr void primeFactorize (T n, OutputIterator result) noexcept {
                for (T i = 2; i * i <= n; ++i) {
                        if (n % i != 0) {
                                continue;
                        }

                        int cnt = 0;
                        while (n % i == 0) {
                                ++cnt;
                                n /= i;
                        }

                        *result = {i, cnt};
                        ++result;
                }

                if (n != 1) {
                        *result = {n, 1};
                }
        }
}
