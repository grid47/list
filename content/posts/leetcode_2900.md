
+++
authors = ["Crafted by Me"]
title = "Leetcode 2900: Longest Unequal Adjacent Groups Subsequence I"
date = "2016-11-24"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

