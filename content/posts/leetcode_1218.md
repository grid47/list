
+++
authors = ["Yasir"]
title = "Leetcode 1218: Longest Arithmetic Subsequence of Given Difference"
date = "2021-06-28"
description = "Solution to Leetcode 1218"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        map<int, int> mp;
        int ans = 1;
        for(int x: arr) {
            mp[x] = 1 + max(mp[x - diff], mp.count(x)? mp[x] -1 :0);
            ans = max(ans, mp[x]);
        }
        return ans;
    }
};
{{< /highlight >}}

