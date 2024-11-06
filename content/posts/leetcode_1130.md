
+++
authors = ["Crafted by Me"]
title = "Leetcode 1130: Minimum Cost Tree From Leaf Values"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1130: Minimum Cost Tree From Leaf Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int res = 0;
        
        vector<int> stk = { INT_MAX };
        for(int a : arr) {
            while(stk.back() <= a) {
                int mid = stk.back();
                stk.pop_back();
                res += mid * min(stk.back(), a);
            }
            stk.push_back(a);
        }
        
        for(int i = 2; i < stk.size(); i++) {
            res += stk[i] * stk[i - 1];
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1130.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1131: Maximum of Absolute Value Expression](https://grid47.xyz/posts/leetcode_1131) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
