
+++
authors = ["grid47"]
title = "Leetcode 1513: Number of Substrings With Only 1s"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1513: Number of Substrings With Only 1s in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-substrings-with-only-1s/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSub(string s) {
        long cnt = 0, mod = (int) 1e9 + 7;

        long tmp = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                tmp++;
            }
            
            if(s[i] == '0' || i == n - 1) {
                cnt = (cnt + tmp * (tmp + 1) / 2) % mod;
                tmp = 0;
            }
            
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1513.md" >}}
---
{{< youtube 9cPoRqw5I_8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1514: Path with Maximum Probability](https://grid47.xyz/posts/leetcode-1514-path-with-maximum-probability-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}