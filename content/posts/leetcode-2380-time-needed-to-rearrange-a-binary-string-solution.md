
+++
authors = ["grid47"]
title = "Leetcode 2380: Time Needed to Rearrange a Binary String"
date = "2024-03-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2380: Time Needed to Rearrange a Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int seconds = 0;
        bool changed = true;
        while(changed) {
            changed = false;
            for(int i = 0; i < s.size() - 1; i++) {
                if(s[i] == '0' && s[i + 1] == '1') {
                    swap(s[i], s[i + 1]);
                    changed = true;
                    i++;
                }
            }
            seconds += changed;
        }
        return seconds;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2380.md" >}}
---
{{< youtube fP5kg4ETjUc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2381: Shifting Letters II](https://grid47.xyz/posts/leetcode-2381-shifting-letters-ii-solution/) |
| --- |
