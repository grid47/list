
+++
authors = ["Yasir"]
title = "Leetcode 217: Contains Duplicate"
date = "2024-03-25"
description = "Solution to Leetcode 217"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/contains-duplicate/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> ma;
        for(int x: nums)
            if(ma.count(x)) return true;
        else ma[x] = 1;
        return false;
    }
};
{{< /highlight >}}

