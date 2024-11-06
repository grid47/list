
+++
authors = ["Crafted by Me"]
title = "Leetcode 1177: Can Make Palindrome from Substring"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1177: Can Make Palindrome from Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/can-make-palindrome-from-substring/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        vector<bool> ans;
        
        vector<int> pt(1,0);
        int mask = 0;
        
        for(int i = 0; i < s.length(); i++) {
        pt.push_back(mask ^= 1 << (s[i] - 'a'));
        }
        
        
        for(int i = 0; i < q.size(); i++) {
        
auto &v = q[i];

  
int cnt = __builtin_popcount(pt[v[1]+1] ^ pt[v[0]]);

    ans.push_back(cnt/2 <= v[2]);
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1177.md" >}}
---
{{< youtube tCr-y-1P2J8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1178: Number of Valid Words for Each Puzzle](https://grid47.xyz/posts/leetcode_1178) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

