
+++
authors = ["Crafted by Me"]
title = "Leetcode 1816: Truncate Sentence"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1816: Truncate Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/truncate-sentence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string truncateSentence(string s, int k) {
        int count =0;
        string ans="";
        for(auto x:s)
        {
            if(x==' ')
                count++;
            if(count==k)
                break;
            ans+=x;
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1816.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1817: Finding the Users Active Minutes](https://grid47.xyz/posts/leetcode_1817) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

