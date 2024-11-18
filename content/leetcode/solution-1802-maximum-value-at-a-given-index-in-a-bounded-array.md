
+++
authors = ["grid47"]
title = "Leetcode 1802: Maximum Value at a Given Index in a Bounded Array"
date = "2024-05-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1802: Maximum Value at a Given Index in a Bounded Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Binary Search","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool can(long long pk, long long n, long long i, long long sum) {
        sum -= n;
        long j = n - i - 1;
        
    long long need = pk * pk - ((pk > i ? (pk - i - 1) * (pk - i) : 0) + (pk > j? (pk - j - 1) * (pk - j): 0)) / 2;
        
        return sum - need >= 0;
    }
    
    int maxValue(int n, int index, int mx) {
        
        int ans = 0, l = 0, r = mx;
        
        while(l <= r) {
            long mid = l + (r - l + 1) / 2;
            // cout << mid << " ";
            if(can(mid, n, index, mx)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        
        return ans + 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1802.md" >}}
---
{{< youtube o3H1ccp2ckc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1805: Number of Different Integers in a String](https://grid47.xyz/leetcode/solution-1805-number-of-different-integers-in-a-string/) |
| --- |
