
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2789: Largest Element in an Array after Merge Operations"
date = "2017-03-12"
description = "Solution to Leetcode 2789"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxArrayValue(vector<int>& in) {

        int n = in.size();        
        vector<long long> nums(n, 0);
        
        for(int i = 0; i < n; i++)
            nums[i] = in[i];

        long long res = nums[n - 1];
        
        for(int i = n - 1; i >= 0; i--) {
            res = max(res, (long long)nums[i]);
            if(i > 0 && nums[i] >= nums[i - 1]) {
                nums[i - 1] += nums[i];
            }
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

