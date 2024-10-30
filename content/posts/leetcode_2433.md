
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2433: Find The Original Array of Prefix Xor"
date = "2018-03-04"
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
{{< youtube idcT-p_DDrI >}}
**Code:**

{{< highlight cpp >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

