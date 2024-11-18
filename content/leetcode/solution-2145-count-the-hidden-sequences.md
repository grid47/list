
+++
authors = ["grid47"]
title = "Leetcode 2145: Count the Hidden Sequences"
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2145: Count the Hidden Sequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "kEhFfpz-qps"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/count-the-hidden-sequences/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfArrays(vector<int>& diff, long lower, long upper) {
        // last - fist of n + 1 seq
        
        long mn = 0, mx = 0, x = 0;

        for(int k : diff) {
            x += k;
            mx = max(mx, x);
            mn = min(mn, x);
        }
        
        int sum = mx - mn;
        if (upper - lower < sum)
            return 0;
        else {
            
            return (int)(upper - lower) - sum + 1;
            
        }
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2145.md" >}}
---
{{< youtube kEhFfpz-qps >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2146: K Highest Ranked Items Within a Price Range](https://grid47.xyz/leetcode/solution-2146-k-highest-ranked-items-within-a-price-range/) |
| --- |
