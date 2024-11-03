
+++
authors = ["Crafted by Me"]
title = "Leetcode 1561: Maximum Number of Coins You Can Get"
date = "2020-07-25"
description = "In-depth solution and explanation for Leetcode 1561: Maximum Number of Coins You Can Get in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---
{{< youtube hPe9Z3TiUrA >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

