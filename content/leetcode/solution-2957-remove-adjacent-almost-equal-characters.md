
+++
authors = ["grid47"]
title = "Leetcode 2957: Remove Adjacent Almost-Equal Characters"
date = "2024-01-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2957: Remove Adjacent Almost-Equal Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-adjacent-almost-equal-characters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int n = s.size();
        int i = 1, cnt = 0;
        while(i < n) {
            if(s[i] == s[i - 1] || abs(s[i] - s[i - 1]) == 1) cnt++, i += 2;
            else i++;
        }
        return cnt;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2957.md" >}}
---
{{< youtube PjIWjV-Y5YQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2958: Length of Longest Subarray With at Most K Frequency](https://grid47.xyz/leetcode/solution-2958-length-of-longest-subarray-with-at-most-k-frequency/) |
| --- |
