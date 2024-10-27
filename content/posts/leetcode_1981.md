
+++
authors = ["Yasir"]
title = "Leetcode 1981: Minimize the Difference Between Target and Chosen Elements"
date = "2019-05-27"
description = "Solution to Leetcode 1981"
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

{{< highlight html >}}
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

