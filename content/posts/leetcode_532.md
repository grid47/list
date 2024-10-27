
+++
authors = ["Yasir"]
title = "Leetcode 532: K-diff Pairs in an Array"
date = "2023-05-15"
description = "Solution to Leetcode 532"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-diff-pairs-in-an-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i : nums)
            mp[i]++;
        int res = 0;
        for(auto const &[i, j] : mp)
            if((k > 0 && mp.count(i - k)) ||
              (k == 0 && (j > 1)) )
                res++;
        return res;
    }
};
{{< /highlight >}}

