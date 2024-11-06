
+++
authors = ["Crafted by Me"]
title = "Leetcode 2272: Substring With Largest Variance"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2272: Substring With Largest Variance in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/substring-with-largest-variance/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestVariance(string s) {
        
        int ans = 0;
        unordered_set<int> num(s.begin(), s.end());
        
        for(char a: num)
        for(char b: num) {
            int var = 0, first_b = 0, has_b = 0;
            for(char c: s) {
                
                var += c == a;
                
                if(c == b) {
                    has_b = true;
                    if(first_b && var >= 0)
                        first_b = false;
                    else if(--var < 0) {
                        var = -1;
                        first_b = true;
                    }
                }
                ans = max(ans, has_b? var: 0);                
            }

        }
        return ans;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2272.md" >}}
---
{{< youtube MlnxbPLbnx4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2273: Find Resultant Array After Removing Anagrams](https://grid47.xyz/posts/leetcode_2273) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
