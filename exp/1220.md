class Solution {
public:
    int n, mod = (int) 1e9 + 7;
    vector<vector<int>> mem;
    int dp(int prv, int cur) {
        if(cur == n) return 1;
        if(mem[prv][cur] != -1) return mem[prv][cur];
        long ans = 0;
        switch(prv) {
            case 0:
                ans = (ans + dp(1, cur + 1)) % mod;
                ans = (ans + dp(2, cur + 1)) % mod;
                ans = (ans + dp(3, cur + 1)) % mod;
                ans = (ans + dp(4, cur + 1)) % mod;
                ans = (ans + dp(5, cur + 1)) % mod;
            break;
            case 1:
        /*  a -> xeixu  e -> axixx  i -> xexox  o -> xxixx  u -> xxiox  */            
                // ans = (ans + dp(1, cur + 1)) % mod;
                ans = (ans + dp(2, cur + 1)) % mod;
                ans = (ans + dp(3, cur + 1)) % mod;
                // ans = (ans + dp(4, cur + 1)) % mod;
                ans = (ans + dp(5, cur + 1)) % mod;
            break;
            case 2:
                ans = (ans + dp(1, cur + 1)) % mod;
                // ans = (ans + dp(2, cur + 1)) % mod;
                ans = (ans + dp(3, cur + 1)) % mod;
                // ans = (ans + dp(4, cur + 1)) % mod;
                // ans = (ans + dp(5, cur + 1)) % mod;
            break;
            case 3:
                // ans = (ans + dp(1, cur + 1)) % mod;
                ans = (ans + dp(2, cur + 1)) % mod;
                // ans = (ans + dp(3, cur + 1)) % mod;
                ans = (ans + dp(4, cur + 1)) % mod;
                // ans = (ans + dp(5, cur + 1)) % mod;
            break;
            case 4:
                // ans = (ans + dp(1, cur + 1)) % mod;
                // ans = (ans + dp(2, cur + 1)) % mod;
                ans = (ans + dp(3, cur + 1)) % mod;
                // ans = (ans + dp(4, cur + 1)) % mod;
                // ans = (ans + dp(5, cur + 1)) % mod;
            break;
            case 5:
                // ans = (ans + dp(1, cur + 1)) % mod;
                // ans = (ans + dp(2, cur + 1)) % mod;
                ans = (ans + dp(3, cur + 1)) % mod;
                ans = (ans + dp(4, cur + 1)) % mod;
                // ans = (ans + dp(5, cur + 1)) % mod;
            break;                                                                        
        }

        return mem[prv][cur] = ans;
    }

    int countVowelPermutation(int n) {
        this->n = n;
        mem.resize(8, vector<int>(n + 1, -1));
        return dp(0, 0);
    }
};