
+++
authors = ["grid47"]
title = "Leetcode 67: Add Binary"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 67: Add Binary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Bit Manipulation","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-binary/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/67.webp" 
    alt="Two radiant binary sequences gently merging into a new, illuminated result."
    caption="Solution to LeetCode 67: Add Binary Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string addBinary(string a, string b) {
        
        int cr = 0;
        string res = "";
        while(!a.empty() || !b.empty() || cr) {
            if(!a.empty()) {
                cr += a.back() - '0';
                a.pop_back();
            }
            if(!b.empty()) {
                cr += b.back() - '0';
                b.pop_back();
            }
            
            res = to_string(cr % 2) + res;
            cr /= 2;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/67.md" >}}
---
{{< youtube M9foA9gcL98 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #70: Climbing Stairs](https://grid47.xyz/posts/leetcode-70-climbing-stairs-solution/) |
| --- |
