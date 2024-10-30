
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2053: Kth Distinct String in an Array"
date = "2019-03-19"
description = "Solution to Leetcode 2053"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/kth-distinct-string-in-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (auto &s : arr)
            ++mp[s];
        for (auto &s : arr)
            if (mp[s] == 1 && --k == 0)
                return s;
        return "";
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

