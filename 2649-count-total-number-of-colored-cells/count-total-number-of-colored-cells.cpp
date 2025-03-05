class Solution {
public:
    long long coloredCells(int n) {
        long long tmp = (long long)n;
        return tmp * tmp + (tmp-1) * (tmp-1);
    }
};