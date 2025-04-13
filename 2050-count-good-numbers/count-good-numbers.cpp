class Solution {
public:
    const int MOD = 1e9 + 7;
    int fast_exp(long long x, long long n) {
        long long ans = 1;
        long long base = x;
        while (n != 0) {
            if (n & 1) {
                ans = ans * base % MOD;
            }
            base = base * base % MOD;
            n >>= 1;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long oddIdxs = n / 2;
        long long evenIdxs = (n + 1) / 2;
        return (long long)fast_exp(5, evenIdxs) * fast_exp(4, oddIdxs) % MOD;
    }
};