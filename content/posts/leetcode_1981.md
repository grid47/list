
+++
authors = ["Crafted by Me"]
title = "Leetcode 1981: Minimize the Difference Between Target and Chosen Elements"
date = "2019-06-01"
description = "In-depth solution and explanation for Leetcode 1981: Minimize the Difference Between Target and Chosen Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---

| Next : [LeetCode #1982: Find Array Given Subset Sums](https://grid47.xyz/posts/leetcode_1982) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

