
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 3046: Split the Array"
date = "2016-06-27"
description = "Solution to Leetcode 3046"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-the-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        map<int, int> mp;
        for(int x: nums) {
            mp[x]++;
            if(mp[x] > 2) return false;
        }
        return true;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

