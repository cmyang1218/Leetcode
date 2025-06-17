class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int cnt = 0;
        int idx1 = 0, idx2 = 0;
        while (idx1 < word1.length() && idx2 < word2.length()) {
            if (cnt % 2) {
                res += word2[idx2++];
            }else {
                res += word1[idx1++];
            }
            cnt++;
        }
        if (idx1 < word1.length()) {
            res += word1.substr(idx1, word1.length()-idx1);
        }else if (idx2 < word2.length()) {
            res += word2.substr(idx2, word2.length()-idx2);
        }
        return res;
    }
};