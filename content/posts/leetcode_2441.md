
+++
authors = ["Crafted by Me"]
title = "Leetcode 2441: Largest Positive Integer That Exists With Its Negative"
date = "2018-02-26"
description = "In-depth solution and explanation for Leetcode 2441: Largest Positive Integer That Exists With Its Negative in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
int findMaxK(vector<int>& nums) {
    int arr[2001] = {}, res = -1;
    for (int n : nums) {
        if (arr[-n + 1000])
            res = max(res, abs(n));
        ++arr[n + 1000];        
    }
    return res;
}
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2442: Count Number of Distinct Integers After Reverse Operations](https://grid47.xyz/posts/leetcode_2442) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

