
+++
authors = ["Crafted by Me"]
title = "Leetcode 1774: Closest Dessert Cost"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1774: Closest Dessert Cost in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/closest-dessert-cost/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int target;
    vector<int> top;
    
    int closestCost(vector<int>& base, vector<int>& top, int target) {
        this->target = target;
        this->top = top;
        int ans = 0;
        for(int i = 0; i < base.size(); i++)
            ans = close(ans, dfs(0, base[i]));
        return ans;
    }
    
    
    int dfs(int idx, int sum) {
        if(idx >= top.size()) return sum;
        
        int a = dfs(idx + 1, sum + top[idx]);
        int b = dfs(idx + 1, sum + 2 * top[idx]);
        int c = dfs(idx + 1, sum);
        
        return close(a, close(b, c));
    }
    
    int close(int a, int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        
        if(abs(target - a) == abs(target - b))
            return a < b? a: b;
        
        return abs(target - a) < abs(target - b) ? a: b;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1774.md" >}}
---
{{< youtube Iom0aF6DOwU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1775: Equal Sum Arrays With Minimum Number of Operations](https://grid47.xyz/posts/leetcode_1775) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
