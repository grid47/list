
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 388: Longest Absolute File Path"
date = "2023-10-07"
description = "Solution to Leetcode 388"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

