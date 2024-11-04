
+++
authors = ["Crafted by Me"]
title = "Leetcode 2216: Minimum Deletions to Make Array Beautiful"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2216: Minimum Deletions to Make Array Beautiful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i++)
            if(nums[i] == nums[i + 1] && (i - ans) % 2 == 0) ans++;
        
        return ans + (nums.size() - ans) % 2;
    }
};
{{< /highlight >}}


---
{{< youtube VgyrTbLZie8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2217: Find Palindrome With Fixed Length](https://grid47.xyz/posts/leetcode_2217) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

