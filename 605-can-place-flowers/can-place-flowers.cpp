class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int placable = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            bool emptyLeft = (i == 0) || (flowerbed[i-1] == 0);
            bool emptyRight = (i == size-1) || (flowerbed[i+1] == 0);
            if (flowerbed[i] == 0 && emptyLeft && emptyRight) {
                flowerbed[i] = 1;
                placable++;
            }
        }
        return placable >= n;
    }
};