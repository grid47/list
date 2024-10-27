
+++
authors = ["Yasir"]
title = "Leetcode 2433: Find The Original Array of Prefix Xor"
date = "2018-03-01"
description = "Solution to Leetcode 2433"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res(pref.size());
        res[0] = pref[0];
        for(int i = 1; i < pref.size(); i++)
            res[i] = pref[i] ^ pref[i - 1];
        
        return res;
    }
};
{{< /highlight >}}

