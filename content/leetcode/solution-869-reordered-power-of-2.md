
+++
authors = ["grid47"]
title = "Leetcode 869: Reordered Power of 2"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 869: Reordered Power of 2 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Sorting","Counting","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "rJu123dgDy8"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/reordered-power-of-2/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int c = counter(n);
        for(int i = 0; i < 32; i++)
            if(counter(1<<i) == c) return true;
        return false;
    }

    int counter(int N) {
        int res = 0;
        for(;N; N/=10) res += pow(10, N%10);
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/869.md" >}}
---
{{< youtube rJu123dgDy8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #870: Advantage Shuffle](https://grid47.xyz/leetcode/solution-870-advantage-shuffle/) |
| --- |
