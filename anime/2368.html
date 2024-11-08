class Solution {
    int ans;
public:
    void solve(vector<vector<int>>& gph, vector<bool> &vis, int i) {
        vis[i] = true;
        for(int n: gph[i]) {
            if(!vis[n]) {
                ans++;
                vis[n] = true;
                solve(gph, vis, n);
            }
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        ans = 1;
        vector<vector<int>> gph(n);
        for(auto e: edges) {
            int u = e[0], v = e[1];
            gph[u].push_back(v);
            gph[v].push_back(u);
        }

        vector<bool> vis(n, false);
        for(auto i: restricted) vis[i] = true;

        solve(gph, vis, 0);
        return ans;
    }
};