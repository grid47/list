
+++
authors = ["Yasir"]
title = "Leetcode 55: Jump Game"
date = "2024-08-31"
description = "Solution to Leetcode 55"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/jump-game/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(mx < i) return false;
            mx = max(mx, i + nums[i]);
            cout << mx << ' ';
            if(mx >= nums.size() - 1) return true;
        }
        return false;
    }
};
{{< /highlight >}}

