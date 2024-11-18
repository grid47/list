
+++
authors = ["grid47"]
title = "Leetcode 2729: Check if The Number is Fascinating"
date = "2024-02-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2729: Check if The Number is Fascinating in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "B1JUo4KREiU"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/check-if-the-number-is-fascinating/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isFascinating(int n) {
        int n1 = 2 * n;
        int n2 = 3 * n;
        vector<bool> yes(10, false); 
        string s = to_string(n) + to_string(n1) + to_string(n2);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') return false;
            if(yes[s[i] - '0']) return false;
            yes[s[i] - '0'] = true;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2729.md" >}}
---
{{< youtube B1JUo4KREiU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2730: Find the Longest Semi-Repetitive Substring](https://grid47.xyz/leetcode/solution-2730-find-the-longest-semi-repetitive-substring/) |
| --- |
