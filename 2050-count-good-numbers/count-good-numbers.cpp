class Solution {
public:
    const int MOD = 1e9 + 7;
    long long fast_exp(long long x, long long n) {
        long long ret = 1, base = x;
        while (n != 0) {
            if (n & 1) 
                ret = ret * base % MOD;
            base = base * base % MOD;
            n >>= 1;
        }
        return ret;
    }

    int countGoodNumbers(long long n) {
        long long evenIdxs = (n + 1) / 2;
        long long oddIdxs = n / 2;
        return fast_exp(5, evenIdxs) * fast_exp(4, oddIdxs) % MOD;
    }
};