
+++
authors = ["grid47"]
title = "Leetcode 880: Decoded String at Index"
date = "2024-08-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 880: Decoded String at Index in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decoded-string-at-index/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    
    public:
    string decodeAtIndex(string s, int k) {
        
        long N = 0, i;
        
        for(i = 0; N < k; i++)
            N = isdigit(s[i])? (s[i] - '0') * N: N +1;
        
        while(i--) {
            if(isdigit(s[i])) {
                N /= (s[i] - '0');
                k %= N;
            }
            else if (k % N-- == 0) {
                return string(1, s[i]);
            }
        }
        
        return "hello yasir";
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/880.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #881: Boats to Save People](https://grid47.xyz/posts/leetcode-881-boats-to-save-people-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
