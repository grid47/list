
+++
authors = ["Crafted by Me"]
title = "Leetcode 810: Chalkboard XOR Game"
date = "2022-08-14"
description = "Solution to Leetcode 810"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/chalkboard-xor-game/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int net = 0;
        for(int x: nums)
            net ^= x;
        return net == 0 || nums.size() % 2 == 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/810.md" >}}
---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

