
+++
authors = ["Yasir"]
title = "Leetcode 45: Jump Game II"
date = "2024-09-10"
description = "Solution to Leetcode 45"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/jump-game-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int cur = 0;
        int far = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            far = max(far, i + nums[i]);
            if(i == cur) {
                cur = far;
                jumps++;
            }
        }
        return jumps;
    }
};
{{< /highlight >}}

