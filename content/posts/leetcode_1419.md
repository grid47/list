
+++
authors = ["Yasir"]
title = "Leetcode 1419: Minimum Number of Frogs Croaking"
date = "2020-12-09"
description = "Solution to Leetcode 1419"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-frogs-croaking/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int cnt[5] = {}, frogs = 0, max_frog = 0;
        for(auto ch : croakOfFrogs) {
            auto n = string("croak").find(ch);
            ++cnt[n];
            if(n == 0) max_frog = max(max_frog, ++frogs);
            else if(--cnt[n - 1] < 0)   return -1;
            else if(n == 4)             --frogs;
        }
        return frogs == 0? max_frog : -1;
    }
};
{{< /highlight >}}

