
+++
authors = ["Crafted by Me"]
title = "Leetcode 1482: Minimum Number of Days to Make m Bouquets"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1482: Minimum Number of Days to Make m Bouquets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int isValid(vector<int> &bloom, int m, int mid, int k) {
        int bough = 0, cnt = 0;
        
        for(int i = 0; i < bloom.size(); i++) {
            if(bloom[i] > mid) {
                cnt = 0;
            } else if(++cnt >= k) {
                cnt = 0;
                bough++;
            }
        }
        if(bough >= m) return true;
        else return false;
    }
    
    int minDays(vector<int>& bloom, int m, int k) {
        int n = bloom.size();
        if((long)m * k > n) return -1;
        
        int l = 1, r = (int) 1e9, result;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(isValid(bloom, m, mid, k)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return result;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1482.md" >}}
---
{{< youtube C43I3Q0JLB0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1483: Kth Ancestor of a Tree Node](https://grid47.xyz/posts/leetcode_1483) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
