
+++
authors = ["grid47"]
title = "Leetcode 1525: Number of Good Ways to Split a String"
date = "2024-06-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1525: Number of Good Ways to Split a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Dynamic Programming","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "lRVpVUC5mQ4"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/number-of-good-ways-to-split-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSplits(string s) {
        map<char, int> left, right;
        
        int n = s.size();
        for(int i = 0; i < n; i++)
            right[s[i]]++;
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            left[s[i]]++;
            right[s[i]]--;
            if(right[s[i]] == 0) right.erase(s[i]);
            if(left.size() == right.size()) cnt++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1525.md" >}}
---
{{< youtube lRVpVUC5mQ4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1529: Minimum Suffix Flips](https://grid47.xyz/leetcode/solution-1529-minimum-suffix-flips/) |
| --- |
