
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1802: Maximum Value at a Given Index in a Bounded Array"
date = "2019-11-24"
description = "Solution to Leetcode 1802"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

