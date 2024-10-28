
+++
authors = ["Coded by Yasir, Explained by GPT"]
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

{{< highlight cpp >}}
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
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

