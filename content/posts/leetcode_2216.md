
+++
authors = ["Crafted by Me"]
title = "Leetcode 2216: Minimum Deletions to Make Array Beautiful"
date = "2018-10-09"
description = "Solution to Leetcode 2216"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i++)
            if(nums[i] == nums[i + 1] && (i - ans) % 2 == 0) ans++;
        
        return ans + (nums.size() - ans) % 2;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

