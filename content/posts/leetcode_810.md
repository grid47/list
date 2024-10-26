
+++
authors = ["Yasir"]
title = "Leetcode 810: Chalkboard XOR Game"
date = "2022-08-09"
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

{{< highlight html >}}
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

