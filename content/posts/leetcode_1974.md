
+++
authors = ["Yasir"]
title = "Leetcode 1974: Minimum Time to Type Word Using Special Typewriter"
date = "2019-06-03"
description = "Solution to Leetcode 1974"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minTimeToType(string word) {
        int res = word.size(), point = 'a';
        for (auto ch : word) {
            res += min(abs(ch - point), 26 - abs(point - ch));
            point = ch;
        }
        return res;
    }
};
{{< /highlight >}}

