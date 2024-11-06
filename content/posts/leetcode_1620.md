
+++
authors = ["Crafted by Me"]
title = "Leetcode 1620: Coordinate With Maximum Network Quality"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1620: Coordinate With Maximum Network Quality in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/coordinate-with-maximum-network-quality/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& tow, int rad) {
        
        int n = tow.size();
    
        int mx = INT_MIN;
        vector<vector<int>> res;
        
        for(int i = 0; i <= 50; i++)
        for(int j = 0; j <= 50; j++) {
            
            int sum = 0;
            for(int k = 0; k < n; k++) {
                int x = tow[k][0], y = tow[k][1];
                float r = sqrt((x - i) * (x - i) + (y - j) * (y - j));
                int ss = 0;
                if(r <= rad) {
                    ss = tow[k][2]/(1 + r);
                }
                sum += ss;
            }
            if(mx < sum) {
                mx = sum;
                res = {{i, j}};
            } else if(mx == sum) {
                res.push_back({i, j});
            }
        }
        sort(res.begin(), res.end());
        return res[0];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1620.md" >}}
---
{{< youtube TqKDnzkRsh0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1621: Number of Sets of K Non-Overlapping Line Segments](https://grid47.xyz/posts/leetcode_1621) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
