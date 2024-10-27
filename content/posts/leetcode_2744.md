
+++
authors = ["Yasir"]
title = "Leetcode 2744: Find Maximum Number of String Pairs"
date = "2017-04-24"
description = "Solution to Leetcode 2744"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-maximum-number-of-string-pairs/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
    int vis[676] = {}, res = 0;
    for (const auto &w : words) {
        res += vis[(w[1] - 'a') * 26 + w[0] - 'a'];
        vis[(w[0] - 'a') * 26 + w[1] - 'a'] = true;
    }
    return res;
}
};
{{< /highlight >}}

