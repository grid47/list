class Solution {
public:
    vector<string> strs;
    int memo[101][105], cmem[101][105];    
    bool check(int idx, int prv) {
        if(cmem[idx][prv] != -1) return cmem[idx][prv];
        for(int i = 0; i < strs.size(); i++) {
            if(strs[i][idx] < strs[i][prv])
                return cmem[idx][prv] = false;
        }
        return cmem[idx][prv] = true;
    }

    int dp(int idx, int prv) {
        if(idx == strs[0].size()) return 0;
        
        if(memo[idx][prv + 1] != -1) return memo[idx][prv + 1];
        
        int ans = dp(idx + 1, prv);
        
        if(prv == -1 || check(idx, prv)) {
            ans = max(ans, dp(idx + 1, idx) + 1);
        }
        
        return memo[idx][prv + 1] = ans;
    }
    
    int minDeletionSize(vector<string>& strs) {
        this->strs = strs;
        memset(memo, -1, sizeof(memo));
        memset(cmem, -1, sizeof(cmem));
        return strs[0].size() - dp(0, -1);
        
    }
};