
+++
authors = ["grid47"]
title = "Leetcode 2207: Maximize Number of Subsequences in a String"
date = "2024-03-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2207: Maximize Number of Subsequences in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        
        long long cnt1 = 0, cnt2 = 0, res = 0, n = text.length();
        
        for(int i = 0; i < n; i++) {
            if(text[i] == pattern[1]) {
                cnt2++;
                res += cnt1;
            }
            if(text[i] == pattern[0]) cnt1++;
        }

        res += max(cnt1, cnt2);
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2207.md" >}}
---
{{< youtube uTt6XMDPPIg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2208: Minimum Operations to Halve Array Sum](https://grid47.xyz/posts/leetcode-2208-minimum-operations-to-halve-array-sum-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
