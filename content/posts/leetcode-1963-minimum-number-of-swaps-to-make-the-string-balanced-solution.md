
+++
authors = ["grid47"]
title = "Leetcode 1963: Minimum Number of Swaps to Make the String Balanced"
date = "2024-04-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1963: Minimum Number of Swaps to Make the String Balanced in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == '[') stk.push(i);
            else if(!stk.empty()) stk.pop();
        }
        
        return (stk.size() + 1) / 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1963.md" >}}
---
{{< youtube 3YDBT9ZrfaU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1968: Array With Elements Not Equal to Average of Neighbors](https://grid47.xyz/posts/leetcode-1968-array-with-elements-not-equal-to-average-of-neighbors-solution/) |
| --- |
