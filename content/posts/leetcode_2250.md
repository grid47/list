
+++
authors = ["Yasir"]
title = "Leetcode 2250: Count Number of Rectangles Containing Each Point"
date = "2018-09-01"
description = "Solution to Leetcode 2250"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rec, vector<vector<int>>& pts) {
        
        int n = pts.size();
        
        vector<int> res(n, 0);
        
        sort(rec.begin(), rec.end());
        
        vector<vector<int>> grid(101);
        
        for(auto it: rec) {
            grid[it[1]].push_back(it[0]);
        }
        
        for(int j = 0; j < n; j++) {
            
            for(int i = pts[j][1]; i <= 100; i++) {
                res[j] += (grid[i].end() - lower_bound(grid[i].begin(), grid[i].end(), pts[j][0]));
            }
            
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

