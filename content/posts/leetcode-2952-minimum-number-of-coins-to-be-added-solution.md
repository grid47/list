
+++
authors = ["grid47"]
title = "Leetcode 2952: Minimum Number of Coins to be Added"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2952: Minimum Number of Coins to be Added in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-coins-to-be-added/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());

        int current_max = 0;
        int additions = 0;
        int index = 0;

        while (current_max < target) {
            if (index < coins.size() && coins[index] <= current_max + 1) {
                current_max += coins[index];
                index++;
            } else {
                current_max += current_max + 1;
                additions++;
            }
        }

        return additions;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2952.md" >}}
---
{{< youtube txrhznINlhM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2956: Find Common Elements Between Two Arrays](https://grid47.xyz/posts/leetcode-2956-find-common-elements-between-two-arrays-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}