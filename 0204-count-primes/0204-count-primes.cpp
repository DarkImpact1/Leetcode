class Solution {
public:
    void sieveOfEratosthenes(int n, vector<int>& prime) {
        for (int i = 2; i * i < n; i++) {  
            if (prime[i] == 1) {
                for (int j = i * i; j < n; j += i) {  
                    prime[j] = 0;
                }
            }
        }
    }

    int countPrimes(int n) {
        if (n <= 2) return 0;  //  Edge case: No primes below 2

        vector<int> prime(n, 1);
        prime[0] = prime[1] = 0;  //  Mark 0 and 1 as non-prime

        sieveOfEratosthenes(n, prime);

        return count(prime.begin(), prime.end(), 1);  //  Count 1s in the vector
    }
};
