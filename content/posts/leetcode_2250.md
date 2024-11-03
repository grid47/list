
+++
authors = ["Crafted by Me"]
title = "Leetcode 2250: Count Number of Rectangles Containing Each Point"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2250: Count Number of Rectangles Containing Each Point in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/description/)

---

**Code:**

{{< highlight cpp >}}
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


---
{{< youtube uCTmN3j2hVU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2251: Number of Flowers in Full Bloom](https://grid47.xyz/posts/leetcode_2251) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

