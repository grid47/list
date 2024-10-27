
+++
authors = ["Yasir"]
title = "Leetcode 2138: Divide a String Into Groups of Size k"
date = "2018-12-21"
description = "Solution to Leetcode 2138"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res((s.size() + k - 1) / k, string(k, fill));
        for (int i = 0; i < s.size(); ++i)
            res[i / k][i % k] = s[i];
        return res;
    }
};
{{< /highlight >}}

