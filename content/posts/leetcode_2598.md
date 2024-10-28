
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2598: Smallest Missing Non-negative Integer After Operations"
date = "2017-09-18"
description = "Solution to Leetcode 2598"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[(nums[i] < 0? (nums[i] % value + value)%value: nums[i]%value)]++;
        }
        int idx = 0, mn = INT_MAX;
        for(int i = 0; i < value; i++) {
            if(mp[i] < mn) {
                idx = i;
                mn = mp[i];
            }
        }
        return mn * value + idx;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

