class Solution {

    long long mod = 1000000007;

public:

    typedef long long ll;

    vector<vector<int>> dp;
    int countHousePlacements(int n) {
        
        dp.resize(n + 1, vector<int> (2, -1));
        
        ll res = ( rec(n, 0) + rec(n, 1) ) % mod;

        return (res * res ) % mod;
    }

    int rec(int n, bool filled) {
        if(n == 1) return 1;
        
        if(dp[n][filled] != -1)
            return dp[n][filled];

        if(filled)  return dp[n][filled] = rec(n - 1, !filled);
        else        return dp[n][filled] = ( rec(n - 1, filled) + rec(n - 1, !filled) ) % mod;
    }

};