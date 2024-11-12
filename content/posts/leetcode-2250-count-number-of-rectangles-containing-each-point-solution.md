
+++
authors = ["grid47"]
title = "Leetcode 2250: Count Number of Rectangles Containing Each Point"
date = "2024-03-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2250: Count Number of Rectangles Containing Each Point in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Binary Indexed Tree","Sorting"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2250.md" >}}
---
{{< youtube uCTmN3j2hVU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2255: Count Prefixes of a Given String](https://grid47.xyz/posts/leetcode-2255-count-prefixes-of-a-given-string-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
