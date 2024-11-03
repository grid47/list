
+++
authors = ["Crafted by Me"]
title = "Leetcode 2146: K Highest Ranked Items Within a Price Range"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2146: K Highest Ranked Items Within a Price Range in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/description/)

---

**Code:**

{{< highlight cpp >}}
class cmp {
    public:
    bool operator()(vector<int> &a, vector<int> &b) {
        if((a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2])) {
            return (a[3] < b[3]);
        } else if((a[0] == b[0]) && (a[1] == b[1])) {
            return (a[2] < b[2]);
        } else if(a[0] == b[0]) {
            return (a[1] < b[1]);
        } else return (a[0] < b[0]);
    }
};

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& price, vector<int>& start, int k) {

        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        q.push(start);

        int dist = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;        
        if(grid[start[0]][start[1]] >= price[0] && grid[start[0]][start[1]] <= price[1])
            pq.push({dist, grid[start[0]][start[1]], start[0], start[1]});
            
        grid[start[0]][start[1]] = 0;
        

        

        
        int dir[] = {0, 1, 0, -1, 0};

        while(!q.empty() && pq.size() < k) {
            
            int sz = q.size();
            dist++;
            while(sz--) {
                
                auto it = q.front();
                // grid[it[0]][it[1]] = 0;                
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int x = it[0] + dir[i], y = it[1] + dir[i + 1];
                    if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0)
                        continue;

                    if(grid[x][y] > 1 && grid[x][y] >= price[0] && grid[x][y] <= price[1]) {
                        pq.push({dist, grid[x][y], x, y});
                    }
                    q.push({x, y});
                    grid[x][y] = 0;                                        
                }
                

            }
        }

        vector<vector<int>> ans;        
        while((ans.size() < k) && !pq.empty()) {
            auto it = pq.top();
            ans.push_back({it[2], it[3]});
            pq.pop();
        }                
        
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube OOBGOENJLYo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2147: Number of Ways to Divide a Long Corridor](https://grid47.xyz/posts/leetcode_2147) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

