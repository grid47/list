class Solution {
public:
    int n;
    vector<int> pox, memo;
    
    int dp(int idx) {
        if(idx == n) return 0;
        
        if(memo[idx] != -1) return memo[idx];
        
        int ans = INT_MIN;

        for(int i = 0; i < 3 && idx + i < n; i++) {
            int sum = pox[idx] - pox[idx + i + 1];
            ans = max(ans, sum + pox[idx + i + 1] - dp(idx + i + 1));
        }

        return memo[idx] = ans;
    }
    
    string stoneGameIII(vector<int>& sv) {

        n = sv.size();
        memo.resize(n, -1);
        pox.resize(n + 1, 0);
        for(int i = n - 1; i >= 0; i--)
            pox[i] = pox[i + 1] + sv[i];
        int net = pox[0];
        int alice = dp(0);
        // cout << net << " " << net % 2 << " " << alice << " " << net / 2;
        int bob = net - alice;
        if(bob == alice) return "Tie";
        if(alice > bob) return "Alice";
        return "Bob";
    }
};