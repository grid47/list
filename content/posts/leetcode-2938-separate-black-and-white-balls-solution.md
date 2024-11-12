
+++
authors = ["grid47"]
title = "Leetcode 2938: Separate Black and White Balls"
date = "2024-01-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2938: Separate Black and White Balls in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/separate-black-and-white-balls/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        for (int i = 0, cnt = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                ++cnt;
            else
                res += cnt;
        }
        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2938.md" >}}
---
{{< youtube -VVN0FI0KFo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2942: Find Words Containing Character](https://grid47.xyz/posts/leetcode-2942-find-words-containing-character-solution/) |
| --- |
