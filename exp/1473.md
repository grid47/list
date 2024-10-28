class Solution {
public:

    int m, n;
    vector<vector<int>> cost;
    vector<int> houses;
    vector<vector<vector<int>>> mem;

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        this->m = m;
        this->n = n;
        this->houses = houses;
        this->cost = cost;

        mem.resize(m + 1, vector<vector<int>>(n + 3, vector<int>(m + 1, -1)));
        int ans = dp(0, -1, target);

        return ans >= INT_MAX? -1: ans;
    }

    long dp(int idx, int prv, int tgt) {

        if(idx == m && tgt == 0) return 0;
        if(tgt < 0 || idx == m) return INT_MAX;

        if(mem[idx][prv + 1][tgt] != -1) return mem[idx][prv + 1][tgt];
        
        long res = INT_MAX;
        if(houses[idx] != 0) {
            if(prv != houses[idx])
            res = min(res, dp(idx + 1, houses[idx], tgt - 1));
            else
            res = min(res, dp(idx + 1, prv, tgt));
        } else {
            for(int i = 1; i <= n; i++) {
                if(prv != i)
                res = min(res, cost[idx][i - 1] + dp(idx + 1, i, tgt - 1));
                else
                res = min(res, cost[idx][i - 1] + dp(idx + 1, i, tgt));
            }
        }

        return mem[idx][prv + 1][tgt] = res;
    }


};