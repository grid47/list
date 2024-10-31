
+++
authors = ["Crafted by Me"]
title = "Leetcode 1389: Create Target Array in the Given Order"
date = "2021-01-12"
description = "Solution to Leetcode 1389"
tags = [
    
]
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


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

