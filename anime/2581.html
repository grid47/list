class Solution {
public:
    vector<vector<int>> grid;
    vector<set<int>> guess;
    vector<int> par;
    int ans = 0, k;

    void fill_par(int node, int dad) {
        par[node] = dad;
        for(int it: grid[node]) {
            if(it != dad) fill_par(it, node);
        }
    }
    
    void dfs(int node, int dad, int cnt) {
        if(guess[node].count(dad)) cnt++;
        if(guess[dad].count(node)) cnt--;
        if(cnt >= k) ans++;
        for(int x: grid[node]) {
            if(x != dad) dfs(x, node, cnt);
        }
    }
    
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        this->k = k;
        int n = edges.size() + 1;
        grid.resize(n);
        for(auto e: edges) {
            grid[e[0]].push_back(e[1]);
            grid[e[1]].push_back(e[0]);            
        }
        guess.resize(n);
        for(auto g: guesses) {
            guess[g[0]].insert(g[1]);
        }
        par.resize(n, 0);
        int cnt = 0;
        fill_par(0, -1);
        for(int i = 1; i < n; i++) {
            int dad = par[i];
            if(guess[dad].count(i)) cnt++;
        }
        if(cnt >= k) ans++;
        for(int x: grid[0]) dfs(x, 0, cnt);
        return ans;
    }
};