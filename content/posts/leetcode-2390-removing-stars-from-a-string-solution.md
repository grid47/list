
+++
authors = ["grid47"]
title = "Leetcode 2390: Removing Stars From a String"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2390: Removing Stars From a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/removing-stars-from-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '*') s[j++] = s[i];
            else {
                j--;
            }
        }
        return s.substr(0, j);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2390.md" >}}
---
{{< youtube Qln1aXh2kvQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2391: Minimum Amount of Time to Collect Garbage](https://grid47.xyz/posts/leetcode-2391-minimum-amount-of-time-to-collect-garbage-solution/) |
| --- |
