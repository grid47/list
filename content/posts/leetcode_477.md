
+++
authors = ["Crafted by Me"]
title = "Leetcode 477: Total Hamming Distance"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 477: Total Hamming Distance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/total-hamming-distance/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0, n = nums.size();
        for(int i = 0; i < 32; i++) {
            int bitCnt = 0;
            for(int j = 0; j < nums.size(); j++)
                bitCnt += (nums[j] >> i) & 1;
            
            total += bitCnt * (n - bitCnt);
        }
        return total;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/477.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #479: Largest Palindrome Product](https://grid47.xyz/posts/leetcode_479) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
