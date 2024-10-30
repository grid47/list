
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1561: Maximum Number of Coins You Can Get"
date = "2020-07-23"
description = "Solution to Leetcode 1561"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/)

---
{{< youtube hPe9Z3TiUrA >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

