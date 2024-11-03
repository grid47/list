
+++
authors = ["Crafted by Me"]
title = "Leetcode 1497: Check If Array Pairs Are Divisible by k"
date = "2020-09-27"
description = "In-depth solution and explanation for Leetcode 1497: Check If Array Pairs Are Divisible by k in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> frq(k, 0);
        for(int num : arr) {
            num %= k;
            if (num < 0) num += k;
            frq[num]++;
        }
        if(frq[0]%2 != 0) return false;
        for(int i = 1; i <= k/2; i++)
            if(frq[i] != frq[k - i]) return false;
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1497.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1498: Number of Subsequences That Satisfy the Given Sum Condition](https://grid47.xyz/posts/leetcode_1498) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

