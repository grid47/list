
+++
authors = ["grid47"]
title = "Leetcode 1431: Kids With the Greatest Number of Candies"
date = "2024-06-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1431: Kids With the Greatest Number of Candies in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1432: Max Difference You Can Get From Changing an Integer](https://grid47.xyz/leetcode/solution-1432-max-difference-you-can-get-from-changing-an-integer/) |
| --- |
