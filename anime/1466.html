class Solution {
public:
    int minReorder(int n, vector<vector<int>>& conn) {
        vector<vector<int>> grid(n);
        
        map<int, map<int, bool>> mp;
        
        for(auto it: conn) {
            grid[it[0]].push_back(it[1]);
            grid[it[1]].push_back(it[0]);
            mp[it[0]][it[1]] = true;
        }
        int cnt = 0;
        queue<int> q;
        q.push(0);
        vector<int> vis(n, 0);
        vis[0] = true;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int tmp = q.front();
                q.pop();
                for(int it: grid[tmp]) {
                    if(vis[it]) continue;
                    vis[it] = true;
                    if(mp.count(tmp) && mp[tmp].count(it)) cnt++;
                    q.push(it);
                }
            }
        }
        return cnt;
    }
};