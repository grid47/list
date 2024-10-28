class Solution {
public:

    int mx_lap = 0;
    int dp[1001] = {}, best[1001] = {};
    
    int dfs(int lap, int cT) {
        if(lap == 0) return -cT;
        if(dp[lap]) return dp[lap];
        
        int ans = INT_MAX;
        for(int i = 1; i <= min(mx_lap, lap); i++) {
            ans = min(ans, best[i] + cT + dfs(lap - i, cT));
        }
        return dp[lap] = ans;
    }
    
    int minimumFinishTime(vector<vector<int>>& tires, int cT, int numLaps) {

        for(auto it: tires) {
            long long time = it[0], exp = it[0];
            for(int lap = 1; lap <= numLaps && exp < it[0] + cT; lap++) {
                
                mx_lap = max(mx_lap, lap);
                
                if(best[lap] == 0 || best[lap] > time)
                    best[lap] = time;
                
                exp *= it[1];
                time += exp;
            }
        }

        return dfs(numLaps, cT);
    }
};