
+++
authors = ["Yasir"]
title = "Leetcode 898: Bitwise ORs of Subarrays"
date = "2022-05-14"
description = "Solution to Leetcode 898"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/bitwise-ors-of-subarrays/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, cur, cur2;

        for(int x : arr) {
            cur2 = { x };
            for(int i : cur)        cur2.insert(i | x);
            for(int j : cur = cur2)  res.insert(j);
        }

        return res.size();
    }
};
{{< /highlight >}}

