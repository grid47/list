class Solution {
    vector<int> ans;
    vector<int> vst;
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n, 1);
        vst.resize(n, 0);
        vector<vector<int>> adj(n);
        for(auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vst[0] = 1;
        dfs(n, 0, adj, labels);
        return ans;
    }

    vector<int> dfs(int n, int u, vector<vector<int>>& adj, string &labels) {
        vector<int> cnt(26, 0);
        for(auto v: adj[u]) {
            if(vst[v]) continue;

            vst[v] = 1;
            vector<int> sub = dfs(n, v, adj, labels);
            for(int i = 0; i < 26; i++)
                cnt[i] += sub[i];
        }

        cnt[labels[u] - 'a']++;
        ans[u] = cnt[labels[u] - 'a'];
        return cnt;
    }
};