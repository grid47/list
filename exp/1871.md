class Solution {
public:
    bool canReach(string s, int mnj, int mxj) {
        int n = s.length();
        vector<bool> dp(n, false);
        dp[0] = true;
        int pre = 0;
        for(int i = 0; i < n; i++) {
        
            if(i >= mnj && dp[i - mnj])
                pre++;

            if(i > mxj && dp[i - mxj -1])
                pre--;

            if (pre > 0) dp[i] = s[i] == '0';       
        }
        return dp[n - 1];
    }
};