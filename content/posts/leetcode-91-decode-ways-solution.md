
+++
authors = ["grid47"]
title = "Leetcode 91: Decode Ways"
date = "2024-11-01"
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
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/91.jpeg" 
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #92: Reverse Linked List II](https://grid47.xyz/posts/leetcode-91-decode-ways-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
