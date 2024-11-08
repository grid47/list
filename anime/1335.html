class Solution {
public:
    vector<int> job;
    int memo[301][11];
    int dp(int idx, int d) {

        if(idx == job.size() && d == 0) return 0;
        if(idx == job.size() || d == 0) return INT_MAX;        

        if(memo[idx][d] != -1) return memo[idx][d];

        int mx = job[idx], ans = INT_MAX;

        for(int i = idx; i < job.size(); i++) {
            mx = max(mx, job[i]);
            int ret = dp(i + 1, d - 1);
            if(ret != INT_MAX)
            ans = min(ans, mx + ret);
        }

        return memo[idx][d] = ans;
    }
    
    int minDifficulty(vector<int>& job, int d) {
        if(job.size() < d) return -1;
        
        this->job = job;
        memset(memo, -1, sizeof(memo));
        return dp(0, d);
    }
};