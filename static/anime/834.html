class Solution {
    vector<int> res;
    vector<int> cnt;
    vector<vector<int>> gph;    
public:
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        gph.resize(n, vector<int>());

        for(vector<int> edge: edges) {
            gph[edge[0]].push_back(edge[1]);
            gph[edge[1]].push_back(edge[0]);
        }

        res.resize(n, 0);
        cnt.resize(n, 0);
        dfs1(0, -1);
        dfs2(0, -1);        
        return res;
    }

    void dfs1(int cur, int pre) {
        for (int nxt : gph[cur]) {
            if (pre == nxt) 
                continue;
            dfs1(nxt, cur);
            cnt[cur] += cnt[nxt];
            res[cur] += res[nxt] + cnt[nxt];
        }
        cnt[cur]++;
    }

    void dfs2(int cur, int pre) {
        for (int nxt : gph[cur]) {
            if (pre == nxt) continue;
            res[nxt] = res[cur] - cnt[nxt] + cnt.size() - cnt[nxt];
            dfs2(nxt, cur);
        }
    }

};