
+++
authors = ["Yasir"]
title = "Leetcode 2511: Maximum Enemy Forts That Can Be Captured"
date = "2017-12-13"
description = "Solution to Leetcode 2511"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
int captureForts(vector<int>& forts) {
    int res = 0;
    for (int i = 0, j = 0; i < forts.size(); ++i)
        if (forts[i] != 0) {
            if (forts[j] == -forts[i])
                res = max(res, i - j - 1);
            j = i;
        }
    return res;
}
};
{{< /highlight >}}

