class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles - numExchange >= 0) {
            numBottles -= numExchange;
            numExchange++;
            ans += 1;
            numBottles += 1;
        }
        return ans;
    }
};