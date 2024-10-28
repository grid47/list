class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for (int i = 0; i < words.size(); i++) {
            if (check(words[i], x)) result.push_back(i);
        }
        return result;
    }
private:
    bool check(string& word, char x) {
        for (auto& c : word) {
            if (c == x) return true;
        }
        return false;
    }
};