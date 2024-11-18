
+++
authors = ["grid47"]
title = "Leetcode 1389: Create Target Array in the Given Order"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1389: Create Target Array in the Given Order in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/create-target-array-in-the-given-order/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
        // return b[2] < a[2];
    }
    
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            int j = index[i];
            for(int k = n - 1; k > j; k--)
                ans[k] = ans[k - 1];
            ans[j] = nums[i];
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1389.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1390: Four Divisors](https://grid47.xyz/leetcode/solution-1390-four-divisors/) |
| --- |
