
+++
authors = ["Yasir"]
title = "Leetcode 1431: Kids With the Greatest Number of Candies"
date = "2020-11-27"
description = "Solution to Leetcode 1431"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int ext) {
        int n = candies.size();
        vector<bool> ans(n, false);
        int mx = *max_element(candies.begin(), candies.end());
        for(int i =0; i < n; i++)
            ans[i] = (candies[i]+ ext>= mx);
        return ans;
    }
};
{{< /highlight >}}

