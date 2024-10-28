class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        map<int, pair<int, int>> mp;
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[grid[i][j]] = {i, j};
            }
        }
        if(mp[0] != make_pair(0,0)) return false;
        int p = 0, q = 0;
        for(int i = 1; i < n * n; i++) {
            auto it = mp[i];
            int x = it.first;
            int y = it.second;
            if((abs(x - p) == 1 && abs(y - q) == 2) ||
               (abs(x - p) == 2 && abs(y - q) == 1)) {
                p = x;
                q = y;
            } else return false;
        }
        return true;
    }
};