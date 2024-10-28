
+++
authors = ["Yasir"]
title = "Leetcode 278: First Bad Version"
date = "2024-01-25"
description = "Solution to Leetcode 278"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/first-bad-version/description/)

---

**Code:**

{{< highlight html >}}
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1, e = n;
        while(s < e) {
            int mid = s + (e - s) / 2;
            if(isBadVersion(mid))
                e = mid;
            else s = mid + 1;
        }
        return e;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

