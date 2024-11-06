
+++
authors = ["Crafted by Me"]
title = "Leetcode 1839: Longest Substring Of All Vowels in Order"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1839: Longest Substring Of All Vowels in Order in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestBeautifulSubstring(string s) {
        map<char, int> idx;
        idx['a'] = 0;
        idx['e'] = 1;
        idx['i'] = 2;
        idx['o'] = 3;
        idx['u'] = 4;
        
        int j = 0, res = 0, n = s.size();
        int id = -1;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                if(id != 0) {                 
                    j = i;
                }
                id = 0;
            }else if((idx[s[i]] < id) || (idx[s[i]] - id > 1)) {
                id = -1;
                j = i;
            } else if(idx[s[i]] - id == 1) {
                id = idx[s[i]];
                
            }
            
            if(id == 4) {
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1839.md" >}}
---
{{< youtube hhyzRnwYBwA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1840: Maximum Building Height](https://grid47.xyz/posts/leetcode_1840) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
