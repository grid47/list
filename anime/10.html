class Solution {
public:
    string s, p;
    vector<vector<int>> memo;
    bool dp(int i, int j) {
        if(i == s.size() && j == p.size()) return true;
        if(j == p.size()) return false;
        
        if(memo[i][j] != -1) return memo[i][j];
        int ans = 0;
        if(j + 1 < p.size() && p[j + 1] == '*') {
            if(i < s.size() && (s[i] == p[j] || p[j] == '.'))
                ans |= dp(i+1, j);
            ans |= dp(i, j + 2);
        } else {
            if(i < s.size() && (s[i] == p[j] || p[j] == '.'))
                ans |= dp(i+1, j + 1);            
        }
        
        return memo[i][j] = ans;
    }
    
    bool isMatch(string s, string p) {
        this-> s = s;
        this-> p = p;
        
        memo.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dp(0, 0);
    }
};