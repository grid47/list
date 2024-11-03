
+++
authors = ["Crafted by Me"]
title = "Leetcode 2640: Find the Score of All Prefixes of an Array"
date = "2017-08-11"
description = "In-depth solution and explanation for Leetcode 2640: Find the Score of All Prefixes of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int mx = nums[0];
        long long sum = 0;
        int n = nums.size();
        vector<long long> ans(n, 0);
        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            int scr = nums[i] + mx;
            ans[i] = i == 0? scr: ans[i - 1] + scr;
        }
        return ans;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2641: Cousins in Binary Tree II](https://grid47.xyz/posts/leetcode_2641) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

