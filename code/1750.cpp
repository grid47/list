class Solution {
public:
    int minimumLength(string s) {
        vector<int> pre(3, 0), suf(3, 0);
        
        int i = 0, j = s.size() - 1, len = s.size();
        while(i < j && s[i] == s[j]) {
            char c = s[i];
            while(i < j && s[i] == c) i++;
            while(i < j && s[j] == c) j--;

            len = min(len, j == i? s[i-1]!=s[j]: (j - i + 1));
        }
        return len;
    }
};