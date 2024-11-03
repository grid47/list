
+++
authors = ["Crafted by Me"]
title = "Leetcode 1508: Range Sum of Sorted Subarray Sums"
date = "2020-09-16"
description = "In-depth solution and explanation for Leetcode 1508: Range Sum of Sorted Subarray Sums in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // binary search
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum = (sum + nums[j]) % mod;                
                ans.push_back(sum);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        int res = 0;
        for(int i = left - 1; i < right; i++)
            res = (res + ans[i]) % mod;
        
        return res;
        
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1509: Minimum Difference Between Largest and Smallest Value in Three Moves](https://grid47.xyz/posts/leetcode_1509) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

