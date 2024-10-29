
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 915: Partition Array into Disjoint Intervals"
date = "2022-04-29"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

