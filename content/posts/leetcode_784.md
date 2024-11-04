
+++
authors = ["Crafted by Me"]
title = "Leetcode 784: Letter Case Permutation"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 784: Letter Case Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #785: Is Graph Bipartite?](https://grid47.xyz/posts/leetcode_785) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

