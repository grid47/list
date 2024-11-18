
+++
authors = ["grid47"]
title = "Leetcode 388: Longest Absolute File Path"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 388: Longest Absolute File Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Depth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-absolute-file-path/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/388.webp" 
    alt="A file path glowing as it grows, showing the longest path as it is traced step by step."
    caption="Solution to LeetCode 388: Longest Absolute File Path Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #390: Elimination Game](https://grid47.xyz/leetcode/solution-390-elimination-game/) |
| --- |
