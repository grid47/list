class Solution {
    typedef long long ll;
public:
    long long countPairs(int n, vector<vector<int>>& es) {
        
        vector<vector<int>> g(n, vector<int>());
        for(vector<int> e: es){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            
        }
        vector<bool> vis(n, false);
        ll res = (ll) n * (n - 1) /2;
            
        for(int i = 0; i < n; i++) {
            ll ret = 0;
      if(!vis[i])
      ret = dfs(i, g, vis);
      res -= (ret * (ret -1)/2);
        }
        
        return res;
        
    }
    
    ll dfs(int i, vector<vector<int>> &g, vector<bool> &vis) {
        
        if(vis[i]) return 0;
        vis[i] = true;
        ll res = 1;
        for(int v : g[i]) {
            res += dfs(v, g, vis);
        }
        return res;
    }
    
};