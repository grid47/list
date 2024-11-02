
+++
authors = ["Crafted by Me"]
title = "Leetcode 330: Patching Array"
date = "2022-12-07"
description = "Solution to Leetcode 330"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/patching-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;
        int added = 0, i = 0;
        while(miss <= n) {
            if(i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                added++;
            }
        }
        return added;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/330.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

