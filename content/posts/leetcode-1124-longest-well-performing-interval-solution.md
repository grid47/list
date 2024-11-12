
+++
authors = ["grid47"]
title = "Leetcode 1124: Longest Well-Performing Interval"
date = "2024-07-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1124: Longest Well-Performing Interval in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Stack","Monotonic Stack","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-well-performing-interval/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        
        int n = hours.size(), res = 0, score = 0;
        map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            
            score += (hours[i] > 8) ? 1 : -1;
            
            if(score > 0)res = i + 1;
            else {

                if  (!mp.count(score))    mp[score] = i;
                if  (mp.count(score - 1)) res = max(res, i - mp[score -1]);

            }
        
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1124.md" >}}
---
{{< youtube 1Cu21ILZBx8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1129: Shortest Path with Alternating Colors](https://grid47.xyz/posts/leetcode-1129-shortest-path-with-alternating-colors-solution/) |
| --- |
