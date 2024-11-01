
+++
authors = ["Crafted by Me"]
title = "Leetcode 915: Partition Array into Disjoint Intervals"
date = "2022-05-02"
description = "Solution to Leetcode 915"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-array-into-disjoint-intervals/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int max_i, cur, ans = 1;
        max_i = cur = nums[0];
        
        for(int i = 1; i < n; i++) {
            if(nums[i] < max_i) {
                max_i = cur;
                ans = i + 1;
            } else if (nums[i] > cur)
                cur = nums[i];
        }
        return ans;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/915.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

