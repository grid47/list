class Solution {
public:

    int memo[1001][1001][4];
    vector<int> rate;
    
    int dp(int idx, int prv, int cnt) {
        if(cnt == 3) return 1;
        if(idx == rate.size()) return 0;
        if(memo[idx][prv + 1][cnt] != -1) return memo[idx][prv + 1][cnt];
        int ans = 0;
        if(prv == -1 || rate[idx] > rate[prv]) {
            ans += dp(idx + 1, idx, cnt + 1);
        }
        ans += dp(idx + 1, prv, cnt);
        
        return memo[idx][prv + 1][cnt] = ans;
    }

    int numTeams(vector<int>& rate) {
        this->rate = rate;
        memset(memo, -1, sizeof(memo));
        int res1 = dp(0, -1, 0);

        reverse(this->rate.begin(),this->rate.end());

        memset(memo, -1, sizeof(memo));        
        int res2 = dp(0, -1, 0);

        return res1 + res2;
    }
};