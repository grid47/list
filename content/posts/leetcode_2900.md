
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2900: Longest Unequal Adjacent Groups Subsequence I"
date = "2016-11-22"
description = "Solution to Leetcode 2900"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/)

---
{{< youtube nan >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

