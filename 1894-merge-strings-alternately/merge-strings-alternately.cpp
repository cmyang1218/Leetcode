class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int idx1 = 0, idx2 = 0;
        while (idx1 < word1.length() && idx2 < word2.length()) {
            res += word1[idx1++];
            res += word2[idx2++];
        }
        while (idx1 < word1.length()) {
            res += word1[idx1++];
        }
        while (idx2 < word2.length()) {
            res += word2[idx2++];
        }
        return res;
    }
};