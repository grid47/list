class Solution {
public:
    int mod = (int) 1e9 + 7;
    int n;
    vector<vector<int>> mem;
    
    int dp(int idx, int st) {
        // cout << idx << " " << st << "-";
        if(st == 0 && idx == 0) return 1;
        
        if(st == 0 || idx < 0 || idx >= n || st < idx) return 0;
        
        if(mem[idx][st] != -1) return mem[idx][st];

        long ans = (long)dp(idx, st - 1) % mod + (long)dp(idx + 1, st - 1)% mod + (long)dp(idx - 1, st - 1)% mod;
        
        return mem[idx][st] = ans % mod;
    }
    
    int numWays(int st, int n) {
        mem.resize(st/2 + 1, vector<int>(st + 1, -1));
        this->n = n;
        return dp(0, st);
    }
};