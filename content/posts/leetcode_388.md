
+++
authors = ["Crafted by Me"]
title = "Leetcode 388: Longest Absolute File Path"
date = "2023-10-11"
description = "In-depth solution and explanation for Leetcode 388: Longest Absolute File Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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

| Next : [LeetCode #389: Find the Difference](https://grid47.xyz/posts/leetcode_389) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

