
+++
authors = ["Yasir"]
title = "Leetcode 2149: Rearrange Array Elements by Sign"
date = "2018-12-10"
description = "Solution to Leetcode 2149"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rearrange-array-elements-by-sign/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int idxpos = 0, idxneg = 1;
        for(int num: nums) {
            if(num > 0) {
                ans[idxpos] = num;
                idxpos += 2;
            }
            if(num < 0) {
                ans[idxneg] = num;
                idxneg += 2;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

