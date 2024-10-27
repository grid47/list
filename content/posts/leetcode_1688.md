
+++
authors = ["Yasir"]
title = "Leetcode 1688: Count of Matches in Tournament"
date = "2020-03-15"
description = "Solution to Leetcode 1688"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-of-matches-in-tournament/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numberOfMatches(int n) {
        if(n==0) return 0;
        if(n==1) return 0;
        int ans = n / 2;
        if(n & 1)
        ans += numberOfMatches(n/2 + 1);
        else
        ans += numberOfMatches(n/2);
        return ans;
    }
};
{{< /highlight >}}

