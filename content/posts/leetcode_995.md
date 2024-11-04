
+++
authors = ["Crafted by Me"]
title = "Leetcode 995: Minimum Number of K Consecutive Bit Flips"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 995: Minimum Number of K Consecutive Bit Flips in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Sliding Window","Greedy"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), flipped = 0, res = 0;
        vector<int> hasFlipped(n, 0);
        vector<int> tmp = nums;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k) flipped ^= hasFlipped[i - k];
            if (flipped == nums[i]) {
                if (i + k > nums.size()) return -1;
                flipped ^= 1;
                hasFlipped[i] = 1;
                res++;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/995.md" >}}
---
{{< youtube Fv3M9uO5ovU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #996: Number of Squareful Arrays](https://grid47.xyz/posts/leetcode_996) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

