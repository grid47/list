
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2090: K Radius Subarray Averages"
date = "2019-02-08"
description = "Solution to Leetcode 2090"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-radius-subarray-averages/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> psum(n, 0);
        vector<int> avg(n, 0);
        psum[0] = nums[0];
        for(int i = 1; i < n; i++)
            psum[i] = psum[i - 1] + nums[i];
        
        for(int i = 0; i < n; i++) {
            if(i - k < 0 || i + k >= n) {
                avg[i] = -1;
            } else {
                avg[i] = (psum[i + k] - ((i - k) == 0? 0: psum[i - k - 1])) / (2 * k + 1);
            }
        }
        return avg;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

