
+++
authors = ["Crafted by Me"]
title = "Leetcode 2475: Number of Unequal Triplets in Array"
date = "2018-01-23"
description = "In-depth solution and explanation for Leetcode 2475: Number of Unequal Triplets in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-unequal-triplets-in-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
int unequalTriplets(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int n : nums)
        ++m[n];
    int res = 0, left = 0, right = nums.size();
    for (auto [n, cnt] : m) {
        right -= cnt;
        res += left * cnt * right;
        left += cnt;
    }
    return res;
}
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2476: Closest Nodes Queries in a Binary Search Tree](https://grid47.xyz/posts/leetcode_2476) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

