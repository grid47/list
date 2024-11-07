
+++
authors = ["Crafted by Me"]
title = "Leetcode 2784: Check if Array is Good"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2784: Check if Array is Good in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-array-is-good/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int cnt[201] = {}, n = nums.size() - 1;
        for (auto num : nums)
            ++cnt[num];
        return all_of(begin(cnt) + 1, begin(cnt) + n, [](int c){ return c == 1; }) && cnt[n] == 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2784.md" >}}
---
{{< youtube le-u0OA8HMM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2785: Sort Vowels in a String](https://grid47.xyz/posts/leetcode_2785) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
