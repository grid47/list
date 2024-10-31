
+++
authors = ["Crafted by Me"]
title = "Leetcode 2952: Minimum Number of Coins to be Added"
date = "2016-10-02"
description = "Solution to Leetcode 2952"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

