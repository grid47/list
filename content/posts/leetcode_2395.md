
+++
authors = ["Crafted by Me"]
title = "Leetcode 2395: Find Subarrays With Equal Sum"
date = "2018-04-13"
description = "In-depth solution and explanation for Leetcode 2395: Find Subarrays With Equal Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-subarrays-with-equal-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
    unordered_set<int> s;
    for (int i = 1; i < nums.size(); ++i)
        if(!s.insert(nums[i - 1] + nums[i]).second)
            return true;
    return false;
  }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2396: Strictly Palindromic Number](https://grid47.xyz/posts/leetcode_2396) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

