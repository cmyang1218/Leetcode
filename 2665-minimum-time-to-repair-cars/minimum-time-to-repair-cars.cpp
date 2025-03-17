class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long minRanks = *min_element(ranks.begin(), ranks.end());
        long long left = 1, right = minRanks * cars * cars;
        while (left <= right) {
            long long mid  = left + (right - left) / 2;
            long long carRepaired = 0;
            for (auto rank : ranks) {
                carRepaired += (long long)sqrt(mid / rank);
            }
            if (carRepaired < cars) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return left;
    }
};