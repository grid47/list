
+++
authors = ["Yasir"]
title = "Leetcode 1014: Best Sightseeing Pair"
date = "2022-01-19"
description = "Solution to Leetcode 1014"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/best-sightseeing-pair/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {

        int res = 0, cur = 0;

        for(int x : val) {
            res = max(res, cur + x);
            cur = max(cur, x) - 1;
        }

        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

