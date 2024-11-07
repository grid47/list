
+++
authors = ["Crafted by Me"]
title = "Leetcode 131: Palindrome Partitioning"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 131: Palindrome Partitioning in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/palindrome-partitioning/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        bt(ans, tmp, s, 0);
        return ans;
    }
    
    void bt(vector<vector<string>> &ans, vector<string> &tmp, string s, int idx) {
        if(idx == s.size()) {
            ans.push_back(tmp);
            return;
        }
        
        for(int i = idx; i < s.size(); i++) {
            if(isPal(s, idx, i)) {
              
                tmp.push_back(s.substr(idx, i - idx + 1));
                bt(ans, tmp, s, i + 1);
                tmp.pop_back();
            }
        }
    }
    
    bool isPal(string s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/131.md" >}}
---
{{< youtube 7GlqVABgjJU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #133: Clone Graph](https://grid47.xyz/posts/leetcode_133) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
