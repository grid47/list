
+++
authors = ["Yasir"]
title = "Leetcode 330: Patching Array"
date = "2023-12-03"
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

{{< highlight html >}}
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

