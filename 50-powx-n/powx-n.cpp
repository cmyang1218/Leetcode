class Solution {
public:
    double fast_exp(double x, long long n) {
        double ret = 1.0, base = x;
        while (n != 0) {
            if (n & 1)
                ret = ret * base;
            base = base * base;
            n >>= 1;
        }
        return ret;
    }
    
    double myPow(double x, int n) {
        bool neg = (n < 0);
        long long lln = (long long)n;
        if (neg)
            lln *= -1;
        return neg ? 1 / fast_exp(x, lln) : fast_exp(x, lln);
    }
};