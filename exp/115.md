class Solution {
public:
    int memo[1001][1001];
    string s, t;
    int dp(int i, int j) {
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int res = 0;
        if(s[i] == t[j]) {
            res = dp(i + 1, j+ 1) + dp(i + 1, j);
        } else res = dp(i + 1, j);
        
        return memo[i][j] = res;
    }
    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0);
    }
};