class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
        vector<vector<int>> rnk(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < pref.size(); i++) {
            for(int j = 0; j < pref[i].size(); j++) {
                rnk[i][pref[i][j]] = j;                
            }
        }
        int cnt = 0;
        set<int> items;
        for(int i = 0; i < pairs.size(); i++) {
            for(int j = i + 1; j < pairs.size(); j++) {
                int x = pairs[i][0], y = pairs[i][1];
                int u = pairs[j][0], v = pairs[j][1];
                if((rnk[x][y] > rnk[x][u]) && (rnk[u][x] < rnk[u][v])) {
                    items.insert(x);
                    items.insert(u);
                }
                if((rnk[x][y] > rnk[x][v]) && (rnk[v][x] < rnk[v][u])) {
                    items.insert(x);
                    items.insert(v);
                }
                if((rnk[y][x] > rnk[y][u]) && (rnk[u][y] < rnk[u][v])) {
                    items.insert(y);
                    items.insert(u);
                }
                if((rnk[y][x] > rnk[y][v]) && (rnk[v][y] < rnk[v][u])) {
                    items.insert(y);
                    items.insert(v);
                }
            }
        }
        return items.size();
    }
};