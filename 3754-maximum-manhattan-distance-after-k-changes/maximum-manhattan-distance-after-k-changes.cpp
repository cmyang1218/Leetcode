class Solution {
public:
    int count(int dir1, int dir2, int times) {
        return abs(dir1 - dir2) + times * 2;
    }
    int maxDistance(string s, int k) {
        int north = 0, south = 0, west = 0, east = 0;
        int dist = 0;
        for (int i = 0; i < s.length(); i++) {
            switch(s[i]) {
                case 'N':
                    north++;
                    break;
                case 'S':
                    south++;
                    break;
                case 'W':
                    west++;
                    break;
                case 'E':
                    east++;
                    break;
                default:
                    break;
            }
            int verticalModification = min({north, south, k});
            int horizontalModification = min({west, east, k-verticalModification});
            dist = max(dist, count(north, south, verticalModification) + count(east, west, horizontalModification));
        }
        return dist;
    }
};