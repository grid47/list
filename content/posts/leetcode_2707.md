
+++
authors = ["Crafted by Me"]
title = "Leetcode 2707: Extra Characters in a String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2707: Extra Characters in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Dynamic Programming","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/extra-characters-in-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    set<string> dic;
    string str;
    vector<int> memo;
    int n;
    
    int dp(int idx) {
        
        if(idx == n) return 0;
        
        if(memo[idx] != -1) return memo[idx];
        
        int ans = INT_MAX;
        
        int len = 1;
        for(int i = idx; i < n; i++) {
            
            string s = str.substr(idx, len);
            
            if(dic.count(s)) {
                ans = min(ans, dp(idx + len));
            } else {
                ans = min(ans, len + dp(idx + len));                
            }
            
            len++;
        }
        
        return memo[idx] = ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        
        n = s.size();
        str = s;
        memo.resize(n, -1);
        
        for(auto x: dictionary) {
            dic.insert(x);
        }
        
        return dp(0);
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2707.md" >}}
---
{{< youtube ONstwO1cD7c >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2708: Maximum Strength of a Group](https://grid47.xyz/posts/leetcode_2708) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
