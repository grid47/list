
+++
authors = ["Crafted by Me"]
title = "Leetcode 1981: Minimize the Difference Between Target and Chosen Elements"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1981: Minimize the Difference Between Target and Chosen Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<vector<int>> mat;
    int memo[4901][70];
    int dp(int idx, int sum, int net) {
        if(idx == mat.size()) return abs(sum - net);
        
        if(memo[sum][idx] != -1) return memo[sum][idx];
        
        int ans = INT_MAX;
        for(int i = 0; i < mat[0].size(); i++)
            ans = min(ans, dp(idx + 1, sum + mat[idx][i], net));
        
        return memo[sum][idx] = ans;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        this->mat = mat;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, target);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1981.md" >}}
---
{{< youtube cfQFu_VDISI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1984: Minimum Difference Between Highest and Lowest of K Scores](https://grid47.xyz/posts/leetcode_1984) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
