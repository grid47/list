
+++
authors = ["grid47"]
title = "Leetcode 388: Longest Absolute File Path"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 388: Longest Absolute File Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Depth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-absolute-file-path/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int lengthLongestPath(string ipt) {
        
        vector<int> levels(300, 0);
        
        int level = 0;
        bool isFile = false;
        int ans = 0;
        int len = 0;

        for(char c: ipt) {
            switch(c) {
                case '\n':
                    level = 0, isFile = false, len = 0; break;
                case '\t':
                    level++; break;
                case '.':
                    isFile = true;
                default:
                    len++;
                    levels[level] = len;
                    if(isFile) {
                        ans = max(ans, accumulate(levels.begin(), levels.begin() + level + 1, 0) + level); 
                    }
            }
        }
        return ans;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/388.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #390: Elimination Game](https://grid47.xyz/posts/leetcode_390) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
