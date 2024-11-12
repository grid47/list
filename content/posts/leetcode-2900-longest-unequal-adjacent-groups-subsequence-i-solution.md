
+++
authors = ["grid47"]
title = "Leetcode 2900: Longest Unequal Adjacent Groups Subsequence I"
date = "2024-01-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2900: Longest Unequal Adjacent Groups Subsequence I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Dynamic Programming","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        // Edges 0->1 / 1 -> 0, start has no conseq
        vector<string>ans;
        int flag=-1;
        for(int i=0;i<n;i++){
            if(groups[i]!=flag){
                flag=groups[i];
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2900.md" >}}
---
{{< youtube IJzs5-NDAxc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2901: Longest Unequal Adjacent Groups Subsequence II](https://grid47.xyz/posts/leetcode-2901-longest-unequal-adjacent-groups-subsequence-ii-solution/) |
| --- |
