
+++
authors = ["Crafted by Me"]
title = "Leetcode 77: Combinations"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 77: Combinations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/combinations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        vector<vector<int>> ans;
        vector<int> tmp;
        
            bt(ans, 1, k, tmp);
        return ans;
    }
    
    void bt(vector<vector<int>> &ans, int i, int k, vector<int> &tmp) {
        if(tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        if(i == n + 1) return;
        
        for(int j = i; j <= n; j++) {
            tmp.push_back(j);
            bt(ans, j + 1, k, tmp);
            tmp.pop_back();
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/77.md" >}}
---
{{< youtube q0s6m7AiM7o >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #78: Subsets](https://grid47.xyz/posts/leetcode_78) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
