
+++
authors = ["Crafted by Me"]
title = "Leetcode 1893: Check if All the Integers in a Range Are Covered"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1893: Check if All the Integers in a Range Are Covered in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int line[52] = {};
        for (auto &r : ranges) {
            line[r[0]] += 1;
            line[r[1] + 1] -= 1;
        }
        for (int i = 1, overlaps = 0; i <= right; ++i) {
            overlaps += line[i];
            if (i >= left && overlaps == 0)
                return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1893.md" >}}
---
{{< youtube hZ7QlMbyaKw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1894: Find the Student that Will Replace the Chalk](https://grid47.xyz/posts/leetcode_1894) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
