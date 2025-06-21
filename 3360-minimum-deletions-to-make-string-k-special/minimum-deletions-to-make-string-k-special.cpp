class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (int i = 0; i < word.length(); i++) {
            freq[word[i]]++;
        }
        int minDeletion = word.length();
        for (auto& [_, f1] : freq) {
            int deleted = 0;
            for (auto& [_, f2] : freq) {
                if (f2 < f1) {
                    deleted += f2;
                }else if (f2 > f1 + k) {
                    deleted += f2 - (f1 + k);
                }
            }
            minDeletion = min(minDeletion, deleted);
        }
        return minDeletion;
    }
};