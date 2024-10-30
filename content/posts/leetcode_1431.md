
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1431: Kids With the Greatest Number of Candies"
date = "2020-11-30"
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
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

