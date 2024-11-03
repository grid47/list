
+++
authors = ["Crafted by Me"]
title = "Leetcode 2099: Find Subsequence of Length K With the Largest Sum"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2099: Find Subsequence of Length K With the Largest Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> v(nums.begin(), nums.end());
        nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<int>());
        int cnt = count(v.begin(), v.begin() + k, v[k - 1]);
        
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
            if((nums[i] > v[k - 1]) ||
               (nums[i] == v[k - 1] && (cnt-- > 0)))
                res.push_back(nums[i]);
        
        return res;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2100: Find Good Days to Rob the Bank](https://grid47.xyz/posts/leetcode_2100) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

