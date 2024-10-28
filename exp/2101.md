class Solution {
    #define ll long long int
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> gph(n);
        for(int i = 0; i < n; i++) {

            ll x1 = bombs[i][0];
            ll y1 = bombs[i][1];
            ll r1 = bombs[i][2];

            for(int j = 0; j < n; j++) {
                if(i != j) {
                    ll x2 = abs(x1 - bombs[j][0]);
                    ll y2 = abs(y1 - bombs[j][1]);
                    if(x2 * x2 + y2 * y2 <= r1 * r1) {
                        gph[i].push_back(j);
                    }
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            int c = 0;
            vector<bool> vistd(n, false);
            dfs(gph, vistd, c, i);
            ans = max(ans, c);
        }
        return ans;
    }

    void dfs(vector<vector<int>> &gph, vector<bool> &vstd, int &c, int i) {
        if(vstd[i]) return;
        vstd[i] = true;
        c++;
        for(int j: gph[i])
            if(!vstd[j])
            dfs(gph, vstd, c, j);
    }
};