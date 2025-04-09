class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int Find(int node) {
        if (parent[node] == -1) {
            return node;
        }
        return parent[node] = Find(parent[node]);
    }

    int Union(int nodeA, int nodeB) {
        int pA = Find(nodeA), pB = Find(nodeB);
        if (pA == pB) {
            return 0;
        }else {
            if (rank[pA] >= rank[pB]) {
                parent[pA] = pB;
                rank[pA] += rank[pB];
            }else {
                parent[pB] = pA;
                rank[pB] += rank[pA];
            }
        }
        return 1;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n, -1);
        rank.resize(n, 1);
        int cnt = n;
        for (auto& edge : edges) {
            int nA = edge[0], nB = edge[1];
            cnt -= Union(nA, nB);
        }
        return cnt;
    }
};