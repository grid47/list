class Solution {
    typedef long long ll;
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> s;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int sz = 0; i + sz < m && i - sz >= 0 && j + 2 * sz < n; sz++) {
                    
                    ll x = i, y = j, rsum = 0;
                    do rsum += grid[x++][y++]; while(x < i + sz);
                    if(sz > 0) {
                        
                        do rsum += grid[x--][y++]; while(y < j + 2 * sz);
                        do rsum += grid[x--][y--]; while(x > i - sz);
                        do rsum += grid[x++][y--]; while(x < i);
                        
                    }
                    s.insert(rsum);
                    if(s.size() > 3) {
                        s.erase(begin(s));}
                }
                }
            }
        return vector<int>(rbegin(s), rend(s));
    }
};