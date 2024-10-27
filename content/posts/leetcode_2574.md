
+++
authors = ["Yasir"]
title = "Leetcode 2574: Left and Right Sum Differences"
date = "2017-10-11"
description = "Solution to Leetcode 2574"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/left-and-right-sum-differences/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n + 1, 0), ans(n, 0);
        for(int i = 0; i < n; i++)
            sum[i + 1] = nums[i] + sum[i];
        
        int net = sum[n];
        for(int i = 0; i < n; i++) {
            ans[i] = abs(net - sum[i + 1] - sum[i]);
        }
        return ans;
    }
};
{{< /highlight >}}

