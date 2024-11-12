
+++
authors = ["grid47"]
title = "Leetcode 91: Decode Ways"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 91: Decode Ways in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decode-ways/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/91.webp" 
    alt="A glowing key unlocking multiple pathways, symbolizing decoding and transformation."
    caption="Solution to LeetCode 91: Decode Ways Problem"
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
    vector<int> memo;
    int numDecodings(string s) {
        
        memo.resize(s.size(), -1);
        return !s.size()? 0: ways(0, s);
    }
    
    int ways(int i, string s) {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(memo[i] > -1) return memo[i];
        int res = ways(i + 1, s);
        
        if(i < s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
            res += ways(i + 2, s);
        
        return memo[i] = res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/91.md" >}}
---
{{< youtube 6aEyTjOwlJU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #92: Reverse Linked List II](https://grid47.xyz/posts/leetcode-92-reverse-linked-list-ii-solution/) |
| --- |
