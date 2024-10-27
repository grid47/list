
+++
authors = ["Yasir"]
title = "Leetcode 3168: Minimum Number of Chairs in a Waiting Room"
date = "2016-02-25"
description = "Solution to Leetcode 3168"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minimumChairs(string s) {
        int mx = 0, cnt = 0;
        for(char x: s) {
            cnt += (x == 'E'? 1: -1);
            mx = max(mx, cnt);
        }
        return mx;
    }
};
{{< /highlight >}}

