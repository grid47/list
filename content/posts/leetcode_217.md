
+++
authors = ["Yasir"]
title = "Leetcode 217: Contains Duplicate"
date = "2024-03-26"
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

