class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int grid_size = grid.size();
        vector<int> grid_map(grid_size * grid_size + 1, 0);
        for (int i = 0; i < grid_size; i++) {
            for (int j = 0; j < grid_size; j++) {
                grid_map[grid[i][j]]++;
            }
        }
        int duplicated = 0, replace = 0;
        for (int i = 1; i < grid_map.size(); i++) {
            if (grid_map[i] == 2) {
                duplicated = i;
            }else if (grid_map[i] == 0) {
                replace = i;
            }
        }
        return {duplicated, replace};
    }
};