
+++
authors = ["grid47"]
title = "Leetcode 3137: Minimum Number of Operations to Make Word K-Periodic"
date = "2023-12-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3137: Minimum Number of Operations to Make Word K-Periodic in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string s, int k) {
        
        int n = s.size();
        map<string, int> mp;
        
        for(int i = 0; i < n / k; i++) {
            mp[s.substr(i * k, k)]++;
        }
        
        int lg = 0, net = 0;
        for(auto it: mp) {
            lg = max(lg, it.second);
            net += it.second;
        }
        
        return net - lg;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3137.md" >}}
---
{{< youtube iu8AnEQH4U8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #3138: Minimum Length of Anagram Concatenation](https://grid47.xyz/posts/leetcode-3138-minimum-length-of-anagram-concatenation-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
