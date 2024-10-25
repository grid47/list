
+++
authors = ["Yasir"]
title = "Leetcode 813: Largest Sum of Averages"
date = "2022-08-06"
description = "Solution to Leetcode 813"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-sum-of-averages/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    double memo[200][200];
    double largestSumOfAverages(vector<int>& nums, int k) {
        memset(memo, 0, sizeof(memo));
        int n = nums.size();
        double cur = 0;
        for(int i = 0; i < n; i++) {
            cur += nums[i];
            memo[i + 1][1] = cur / (i+ 1);
        }
        return search(n, k, nums);
    }

    double search(int n, int k, vector<int> &nums) {
        if(memo[n][k] > 0) return memo[n][k];
        double cur = 0;
        for(int i = n - 1; i > 0; i--) {
            cur += nums[i];
            memo[n][k] = max(memo[n][k], search(i, k - 1, nums) + cur / (n - i));
        }
        return memo[n][k];
    }
};
{{< /highlight >}}

