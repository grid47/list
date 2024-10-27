
+++
authors = ["Yasir"]
title = "Leetcode 287: Find the Duplicate Number"
date = "2024-01-15"
description = "Solution to Leetcode 287"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-duplicate-number/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
{{< /highlight >}}

