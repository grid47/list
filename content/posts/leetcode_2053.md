
+++
authors = ["Yasir"]
title = "Leetcode 2053: Kth Distinct String in an Array"
date = "2019-03-16"
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

{{< highlight html >}}
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

