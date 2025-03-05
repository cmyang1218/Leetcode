class Solution {
public:
    bool checkPowersOfThree(int n) {
        int closestPow = 0;
        while (pow(3, closestPow) <= n) {
            closestPow++;
        }
        while (n != 0) {
            if (n - pow(3, closestPow) >= 0)
                n -= pow(3, closestPow);
            if (n - pow(3, closestPow) >= 0)
                return false;
            closestPow--;
        }
        return true;
    }
};