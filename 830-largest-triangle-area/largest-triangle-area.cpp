class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = 0;
        int p1_x, p1_y, p2_x, p2_y, p3_x, p3_y;
        for (int i = 0; i < points.size(); i++) {
            p1_x = points[i][0]; p1_y = points[i][1];
            for (int j = i + 1; j < points.size(); j++) {
                p2_x = points[j][0]; p2_y = points[j][1];
                for (int k = j + 1; k < points.size(); k++) {
                    p3_x = points[k][0], p3_y = points[k][1];
                    area = max(area, 0.5 * abs(p1_x * p2_y + p2_x * p3_y + p3_x * p1_y - p1_x * p3_y - p2_x * p1_y - p3_x * p2_y));
                }
            }
        }
        return area;
    }
};