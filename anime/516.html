class Solution {
public:
    string str;
    vector<vector<int>> memo;
    int dp(int i, int j) {
        if(i == j) return 1;
        if(i == j - 1) return str[i] == str[j]? 2: 1;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        int ans = 0;
        if(str[i] == str[j]) {
            ans = 2 + dp(i + 1, j - 1);
        } else {
            ans = max(dp(i + 1, j), dp(i, j - 1));
        }
        return memo[i][j] = ans;
    }
    
    int longestPalindromeSubseq(string s) {
        str = s;
        int n = s.size();
        memo.resize(n, vector<int>(n, -1));
        return dp(0, n - 1);
    }
};