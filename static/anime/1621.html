class Solution {
public:
    int n;
    int mod = (int) 1e9 + 7;
    int memo[1001][1001][2];
    int dp(int idx, int seg, bool startHere) {
        if(seg == 0) return 1;
        if(idx == n) return 0;

        if(memo[idx][seg][startHere] != -1) return memo[idx][seg][startHere];
        
        int ans = dp(idx + 1, seg, startHere); // will start on next or continue the seg
        if(startHere) {
            ans = (ans + dp(idx + 1, seg, false)) % mod; // stared new line            
        } else {
            ans = (ans + dp(idx, seg - 1, true)) % mod; // end the line here            
        }

        return memo[idx][seg][startHere] = ans;
    }

    int numberOfSets(int n, int k) {
        this->n = n;
        memset(memo, -1, sizeof(memo));
        return dp(0, k, true);
    }
};