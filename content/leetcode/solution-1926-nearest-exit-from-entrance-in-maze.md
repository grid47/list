
+++
authors = ["grid47"]
title = "Leetcode 1926: Nearest Exit from Entrance in Maze"
date = "2024-04-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1926: Nearest Exit from Entrance in Maze in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "KufrcPzbwko"
youtube_upload_date="2024-04-08"
youtube_thumbnail="https://i.ytimg.com/vi/KufrcPzbwko/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/)

---
**Code:**

{{< highlight cpp >}}
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
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1926.md" >}}
---
{{< youtube KufrcPzbwko >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1929: Concatenation of Array](https://grid47.xyz/leetcode/solution-1929-concatenation-of-array/) |
| --- |
