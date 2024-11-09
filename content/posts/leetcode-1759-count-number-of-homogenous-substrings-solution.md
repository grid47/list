
+++
authors = ["grid47"]
title = "Leetcode 1759: Count Number of Homogenous Substrings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1759: Count Number of Homogenous Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-homogenous-substrings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countHomogenous(string s) {
        long long j = 0, cnt = 0, n = s.size();
        int mod = (int) 1e9 + 7;
        
        for(int i = 0; i < n; i++) {
            if(s[j] == s[i]) continue;
            else {
                long long len = i - j;
                cnt += len * (len + 1) / 2;
                j = i;                
            }
        }
        long long len = n - j;
        cnt += len * (len + 1) / 2; 
        return cnt % mod;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1759.md" >}}
---
{{< youtube I3BzhnS9MwA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1760: Minimum Limit of Balls in a Bag](https://grid47.xyz/posts/leetcode-1760-minimum-limit-of-balls-in-a-bag-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
