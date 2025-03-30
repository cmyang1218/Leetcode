class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> inDegrees;
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < numCourses; i++) {
            inDegrees[i] = 0;
        }

        for (auto& preq : prerequisites) {
            int dst = preq[0], src = preq[1];
            graph[src].push_back(dst);
            inDegrees[dst]++;
        }
        queue<int> sources;
        for (int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                sources.push(i);
            }
        }
        vector<int> ret;
        while (!sources.empty()) {
            int curr = sources.front();
            sources.pop();
            ret.push_back(curr);
            for (int i = 0; i < graph[curr].size(); i++) {
                int nextNode = graph[curr][i];
                inDegrees[nextNode]--;
                if (inDegrees[nextNode] == 0) {
                    sources.push(nextNode);
                }
            }
        }
        return ret.size() == numCourses;
    }
};