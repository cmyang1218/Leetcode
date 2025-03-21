class Solution {
public:
    vector<int> parent;
    int Find(int node) {
        if (parent[node] == -1) {
            return node;
        }
        return parent[node] = Find(parent[node]);
    }

    void Union(int node1, int node2) {
        int root1 = Find(node1);
        int root2 = Find(node2);
        if (root1 != root2) {
            parent[root1] = root2;
        }
        return;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> ret;
        parent.resize(n, -1);
        vector<int> cost(n, INT_MAX);
        for (auto& edge : edges) {
            Union(edge[0], edge[1]);
        }
        for (auto& edge : edges) {
            int root = Find(edge[0]);
            cost[root] &= edge[2];
        }

        for (auto& q : query) {
            int root1 = Find(q[0]);
            int root2 = Find(q[1]);
            if (root1 != root2) {
                ret.push_back(-1);
            }else {
                ret.push_back(cost[root1]);
            }
        }
        return ret;
    }

};