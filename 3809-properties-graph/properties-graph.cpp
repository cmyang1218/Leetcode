class Solution {
public:
    bool customIntersection(set<int>& setA, set<int>& setB, int k) {
        vector<int> intersect_vec;
        set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), back_inserter(intersect_vec));
        return (intersect_vec.size() >= k);
    }

    vector<int> parents;

    int Find(int nodeA) {
        if (parents[nodeA] == -1) {
            return nodeA;
        }
        return parents[nodeA] = Find(parents[nodeA]);
    }

    void Union(int nodeA, int nodeB) {
        int parentA = Find(nodeA);
        int parentB = Find(nodeB);
        if (parentA != parentB) {
            parents[parentB] = parentA;
        }
        return;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        parents.resize(properties.size(), -1);
        vector<set<int>> propSetVec(properties.size());
        for (int i = 0; i < properties.size(); i++) {
            set<int> propSet(properties[i].begin(), properties[i].end());
            propSetVec[i] = propSet;
        }
        for (int i = 0; i < propSetVec.size(); i++) {
            for (int j = i + 1; j < propSetVec.size(); j++) {
                if (customIntersection(propSetVec[i], propSetVec[j], k)) {
                    Union(i, j);
                }
            }
        }
        set<int> ccSets;
        for (int i = 0; i < properties.size(); i++) {
            ccSets.insert(Find(i));
        }
        return ccSets.size();
    }
};