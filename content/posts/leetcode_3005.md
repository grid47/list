
+++
authors = ["Crafted by Me"]
title = "Leetcode 3005: Count Elements With Maximum Frequency"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3005: Count Elements With Maximum Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-elements-with-maximum-frequency/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frq;
        int mx = 0;
        for (int num : nums) {
            frq[num]++;
            mx = max(mx, frq[num]);
        }

        int cnt = 0;
        for (auto it : frq) {
            if (it.second == mx)
                cnt++;
        }

        int net = mx * cnt;

        return net;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3005.md" >}}
---
{{< youtube ydihp-cBFqw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3026: Maximum Good Subarray Sum](https://grid47.xyz/posts/leetcode_3026) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
