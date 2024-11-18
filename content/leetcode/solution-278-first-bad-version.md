
+++
authors = ["grid47"]
title = "Leetcode 278: First Bad Version"
date = "2024-10-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 278: First Bad Version in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Binary Search","Interactive"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "E15djRphPj0"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/278.webp"
+++



[`Problem Link`](https://leetcode.com/problems/first-bad-version/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/278.webp" 
    alt="A series of versions, with the first bad one glowing brightly, indicating where the bad version starts."
    caption="Solution to LeetCode 278: First Bad Version Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/278.md" >}}
---
{{< youtube E15djRphPj0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #279: Perfect Squares](https://grid47.xyz/leetcode/solution-279-perfect-squares/) |
| --- |
