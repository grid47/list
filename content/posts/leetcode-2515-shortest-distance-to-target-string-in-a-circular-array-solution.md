
+++
authors = ["grid47"]
title = "Leetcode 2515: Shortest Distance to Target String in a Circular Array"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2515: Shortest Distance to Target String in a Circular Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int closetTarget(vector<string>& words, string target, int s) {
        int n = words.size(), ans = INT_MAX;
        
        for(int i = 0; i < n; i++) 
            if(words[i] == target) 
                ans = min(ans, min(abs(s - i), abs(n - abs(s - i)))); 
        
        return ans == INT_MAX ? -1 : ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2515.md" >}}
---
{{< youtube yTpRd3yvyz0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2516: Take K of Each Character From Left and Right](https://grid47.xyz/posts/leetcode-2516-take-k-of-each-character-from-left-and-right-solution/) |
| --- |
