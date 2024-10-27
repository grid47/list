
+++
authors = ["Yasir"]
title = "Leetcode 1663: Smallest String With A Given Numeric Value"
date = "2020-04-09"
description = "Solution to Leetcode 1663"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        while(k > 0) {
            ans[--n] += min(25, k);
            k -= min(25, k);
        }
        return ans;
    }
};
{{< /highlight >}}

