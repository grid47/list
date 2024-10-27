
+++
authors = ["Yasir"]
title = "Leetcode 1561: Maximum Number of Coins You Can Get"
date = "2020-07-20"
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

**Code:**

{{< highlight html >}}
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

