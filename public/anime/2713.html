class Solution {
public:
    int m, n;
    int maxIncreasingCells(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();

        vector<int> row(m, 0), col(n, 0);
        
        map<int, vector<vector<int>>> mp;
        vector<vector<int>> tmp(m, vector<int>(n, 0));
        set<int> item;
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            mp[-mat[i][j]].push_back({i, j});
            item.insert(-mat[i][j]);
        }
        
        for(int x : item) {
            
            for(auto v: mp[x]) {
                tmp[v[0]][v[1]] = max(row[v[0]], col[v[1]]) + 1;
            }
            
            for(auto v: mp[x]) {
                row[v[0]] = max(row[v[0]], tmp[v[0]][v[1]]);
                col[v[1]] = max(col[v[1]], tmp[v[0]][v[1]]);                
            }
            
        }
        
        return max(*max_element(row.begin(), row.end()), *max_element(col.begin(), col.end()));
    }    
};