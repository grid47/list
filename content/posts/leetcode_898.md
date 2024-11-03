
+++
authors = ["Crafted by Me"]
title = "Leetcode 898: Bitwise ORs of Subarrays"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 898: Bitwise ORs of Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Dynamic Programming","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/bitwise-ors-of-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, cur, cur2;

        for(int x : arr) {
            cur2 = { x };
            for(int i : cur)        cur2.insert(i | x);
            for(int j : cur = cur2)  res.insert(j);
        }

        return res.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/898.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #899: Orderly Queue](https://grid47.xyz/posts/leetcode_899) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

