class Solution {
public:

    int minimumVisitedCells(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({1, {0, 0}});
        dist[0][0] = 1;
        
        while(!pq.empty()) {
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            if(i == m - 1 && j == n - 1) return d;
            pq.pop();
            for(int k = j + 1; k <= min(n - 1, j + grid[i][j]); k++) {
                if(dist[i][k] > d + 1) {
                    dist[i][k] = d + 1;
                    pq.push({d + 1, {i, k}});
                    if(i == m - 1 && k == n - 1) return d + 1;                    
                }
            }
            for(int k = i + 1; k <= min(m - 1, i + grid[i][j]); k++) {
                if(dist[k][j] > d + 1) {
                    dist[k][j] = d + 1;
                    pq.push({d + 1, {k, j}});
                    if(k == m - 1 && j == n - 1) return d + 1;                     
                }
            }            
        }
        return -1;
    }
};