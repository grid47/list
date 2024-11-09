
+++
authors = ["grid47"]
title = "Leetcode 497: Random Point in Non-overlapping Rectangles"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 497: Random Point in Non-overlapping Rectangles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Binary Search","Reservoir Sampling","Prefix Sum","Ordered Set","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> v;
    vector<vector<int>> rect;
public:
    
    int area(vector<int> r) {
        
        return (r[2] - r[0] +1) * (r[3] - r[1] +1);
    }
    
    Solution(vector<vector<int>>& r) {
        rect = r;
        for(vector<int> re : r) {
            v.push_back(area(re) + (v.empty()? 0 : v.back()));
        }
    }
    
    vector<int> pick() {
        int d = rand() % v.back();
        int idz = upper_bound(v.begin(), v.end(), d) - v.begin();
        vector<int> r = rect[idz];
        return {
            rand() % (r[2] - r[0] +1) + r[0],
            rand() % (r[3] - r[1] +1) + r[1]
        };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/497.md" >}}
---
{{< youtube 8kwPXbTMSnk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #498: Diagonal Traverse](https://grid47.xyz/posts/leetcode-498-diagonal-traverse-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
