
+++
authors = ["Yasir"]
title = "Leetcode 169: Majority Element"
date = "2024-05-11"
description = "Solution to Leetcode 169"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/majority-element/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e = nums[0], cnt = 1;
        map<int, int> mp;
        for(int x: nums) {
            mp[x]++;
            if(mp[x] > cnt) {
                cnt = mp[x];
                e = x;
            }
        }
        return e;
    }
};
{{< /highlight >}}

