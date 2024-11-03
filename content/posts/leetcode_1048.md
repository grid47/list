
+++
authors = ["Crafted by Me"]
title = "Leetcode 1048: Longest String Chain"
date = "2021-12-20"
description = "In-depth solution and explanation for Leetcode 1048: Longest String Chain in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-string-chain/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    static bool cmp(string &a, string &b) {
        return a.size() < b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        
        map<string, int> dp;

        int mx = 1;
        
        for(int i = 0; i < words.size(); i++) {
            string w = words[i];
            for(int j = 0; j < w.size(); j++) {
                string w1 = w.substr(0, j) + w.substr(j + 1);
                dp[w] = max(dp[w], dp.count(w1)? dp[w1] + 1: 1);
            }
            mx = max(mx, dp[w]);
        }
        
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1048.md" >}}
---
{{< youtube mB13CkhSe3A >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1049: Last Stone Weight II](https://grid47.xyz/posts/leetcode_1049) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

