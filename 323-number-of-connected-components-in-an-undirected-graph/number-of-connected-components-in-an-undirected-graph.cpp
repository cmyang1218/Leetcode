class Solution {
public:

    int unions(vector<int>& parent, vector<int>& rank, int n1, int n2) {
        int p1 = find(parent, n1), p2 = find(parent, n2);
        if (p1 == p2)
            return 0;
        
        if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }else {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
        return 1;
    }

    int find(vector<int>& parent, int n1) {
        int res = n1;
        while (res != parent[res]) {
            parent[res] = parent[parent[res]];
            res = parent[res];
        }
        return res;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        vector<int> rank(n, 1);
        int ret = n;
        for (auto edge : edges) {
            int n1 = edge[0], n2 = edge[1];
            ret -= unions(parent, rank, n1, n2);
        }
        return ret;
    }
};