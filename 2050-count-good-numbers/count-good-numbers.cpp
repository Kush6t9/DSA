class Solution {
private:
    const long long mod = 1e9 + 7;

    long long power(long long a, long long b) {
        if (b == 0)
            return 1;

        long long half = power(a, b / 2);

        half = (half * half) % mod;

        if (b % 2 == 1)
            half = (half * a) % mod;

        return half;
    }

public:
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return (power(5, even) * power(4, odd)) % mod;
    }
};