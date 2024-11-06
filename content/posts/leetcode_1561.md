
+++
authors = ["Crafted by Me"]
title = "Leetcode 1561: Maximum Number of Coins You Can Get"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1561: Maximum Number of Coins You Can Get in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Greedy","Sorting","Game Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int max = 0;

        int n = piles.size();

        for (int i : piles) {

            if (max < i) max = i;

        }

        vector<int> freq(max + 1, 0);

        for (int i : piles) {

            freq[i]++;

        }

        int coins = 0;

        int chance = n / 3;

        int turn = 1;

        int i = max;

        while (chance != 0) {

            if (freq[i] > 0) {

                if (turn == 1) turn = 0;

                else {

                    chance--;

                    turn = 1;

                    coins += i;

                }

                freq[i]--;

            } else {

                i--;

            }

        }

        return coins;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1561.md" >}}
---
{{< youtube hPe9Z3TiUrA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1562: Find Latest Group of Size M](https://grid47.xyz/posts/leetcode_1562) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

