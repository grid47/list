
+++
authors = ["grid47"]
title = "Leetcode 2951: Find the Peaks"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2951: Find the Peaks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-peaks/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findPeaks(vector<int>& nums) {
        vector<int> res;
        for(int i = 1; i < nums.size() - 1; i++) {
            if((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]))
                res.push_back(i);            
        }

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2951.md" >}}
---
{{< youtube zatlKoGhxCQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2952: Minimum Number of Coins to be Added](https://grid47.xyz/posts/leetcode-2952-minimum-number-of-coins-to-be-added-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}