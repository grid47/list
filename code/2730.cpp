class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        
        vector<int> sem(10, 0);
        int cnt = 0;
        
        int j = 0, len = 1;        
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                cnt++;
                sem[s[i] - '0']++;
            }
            while(cnt > 1 && j < i) {
                if(s[j] == s[j + 1]) {
                    sem[s[j] - '0']--;
                    cnt--;
                }
                j++;
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};