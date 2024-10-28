class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        
        int ans = 1, m = maze.size(), n = maze[0].size();
        int dir[] = {0, 1, 0, -1, 0};
        // vector<vector<int>> vis(m, vector<int>(n, 0));
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int x = it.first + dir[i], y = it.second + dir[i + 1];
                    if(x < 0 || y < 0 || x == m || y == n || maze[x][y] == '+') {
                        continue;
                    }
                    if(x == 0 || y == 0 || x == m - 1 || y == n - 1)
                        return ans;                    
                    maze[x][y] = '+';                    
                    q.push({x, y});
                }
            }
            ans++;
        }
        return -1;
    }
};