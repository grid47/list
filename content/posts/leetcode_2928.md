
+++
authors = ["grid47"]
title = "Leetcode 2928: Distribute Candies Among Children I"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2928: Distribute Candies Among Children I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Combinatorics","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distribute-candies-among-children-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int res = 0;
        for(int i = 0; i <= limit; ++i){
            for(int j = 0; j <= limit; ++j){
                for(int k = 0; k <= limit; ++k){
                    if(i + j + k == n) { res++; }
                }
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2928.md" >}}
---
{{< youtube hVNcZKh8r40 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2932: Maximum Strong Pair XOR I](https://grid47.xyz/posts/leetcode_2932) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
