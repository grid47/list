
+++
authors = ["Crafted by Me"]
title = "Leetcode 1431: Kids With the Greatest Number of Candies"
date = "2020-12-02"
description = "In-depth solution and explanation for Leetcode 1431: Kids With the Greatest Number of Candies in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1431.md" >}}
---
{{< youtube xBpYKQzjjnM >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

