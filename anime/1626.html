class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<pair<int, int>> palyer;
        for(int i = 0; i < n; i++)
        palyer.push_back({ages[i], scores[i]});

        sort(palyer.begin(), palyer.end(), greater<>());
        int ans = 0;
        vector<int> dp(n);
        for(int i = 0; i < n; i++) {
            pair<int, int> young = palyer[i];
            dp[i] = young.second;
            for(int j = 0; j < i; j++) {
                pair<int, int> elder = palyer[j];
                if(young.second <= elder.second)
                dp[i] = max(dp[i], dp[j] + young.second);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};