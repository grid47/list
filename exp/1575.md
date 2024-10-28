class Solution {
public:
    
    int n, mod = (int) 1e9 + 7;
    vector<vector<int>> mem;
    vector<int> loc;
    int countRoutes(vector<int>& loc, int start, int finish, int fuel) {
        n = loc.size();
        this->loc = loc;
        mem.resize(n, vector<int>(fuel + 1, -1));
        return dfs(start, finish, fuel);
    }
    
    int dfs(int st, int ed, int rm) {
        if(rm < 0) return 0;

        if(mem[st][rm] != -1) return mem[st][rm];

        long ans = (st == ed);
        for(int i = 0; i < n ; i++) {
            if(i != st)
            ans = (ans + dfs(i, ed, rm - abs(loc[i] - loc[st]))) % mod;
        }

        return mem[st][rm] = ans;
    }
    
};