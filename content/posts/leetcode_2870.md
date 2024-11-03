
+++
authors = ["Crafted by Me"]
title = "Leetcode 2870: Minimum Number of Operations to Make Array Empty"
date = "2016-12-24"
description = "In-depth solution and explanation for Leetcode 2870: Minimum Number of Operations to Make Array Empty in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums)
            ++m[n];
        int res = 0;
        for (auto [_, cnt] : m) {
            if (cnt == 1)
                return -1;
            res += cnt / 3 + (cnt % 3 > 0);
        }
        return res;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2871: Split Array Into Maximum Number of Subarrays](https://grid47.xyz/posts/leetcode_2871) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

