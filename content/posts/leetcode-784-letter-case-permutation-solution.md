
+++
authors = ["grid47"]
title = "Leetcode 784: Letter Case Permutation"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 784: Letter Case Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/letter-case-permutation/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        bt(ans, s, 0);
        return ans;
    }
    
    void bt(vector<string> &ans, string &s, int i) {
        if(i== s.size()) {
            ans.push_back(s);
            return;
        }
        
        bt(ans, s, i + 1);
        if(isalpha(s[i])) {
            s[i] ^= 1 << 5;
            bt(ans, s, i+1);
        }
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/784.md" >}}
---
{{< youtube qcWClV0FRTs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #785: Is Graph Bipartite?](https://grid47.xyz/posts/leetcode-785-is-graph-bipartite-solution/) |
| --- |
