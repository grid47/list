
+++
authors = ["grid47"]
title = "Leetcode 792: Number of Matching Subsequences"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 792: Number of Matching Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Binary Search","Dynamic Programming","Trie","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-matching-subsequences/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        vector<vector<int>> srch(26);

        for(int i = 0; i < s.size(); i++)
            srch[s[i] - 'a'].push_back(i);
        
        int res = 0;
        
        for(string word : words) {
            int x = -1;
            bool found = true;

            for(char c : word) {
                auto it = upper_bound(srch[c - 'a'].begin(), srch[c - 'a'].end(), x);
                if(it == srch[c - 'a'].end()) {
                    found = false;
                    break;
                } else x = *it;
            }
            
            if(found) res++;
        }
                
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/792.md" >}}
---
{{< youtube 0zMujz5SYoE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #793: Preimage Size of Factorial Zeroes Function](https://grid47.xyz/posts/leetcode-793-preimage-size-of-factorial-zeroes-function-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}