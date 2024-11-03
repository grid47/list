
+++
authors = ["Crafted by Me"]
title = "Leetcode 1525: Number of Good Ways to Split a String"
date = "2020-08-30"
description = "In-depth solution and explanation for Leetcode 1525: Number of Good Ways to Split a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-good-ways-to-split-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSplits(string s) {
        map<char, int> left, right;
        
        int n = s.size();
        for(int i = 0; i < n; i++)
            right[s[i]]++;
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            left[s[i]]++;
            right[s[i]]--;
            if(right[s[i]] == 0) right.erase(s[i]);
            if(left.size() == right.size()) cnt++;
        }
        
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1525.md" >}}
---
{{< youtube lRVpVUC5mQ4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1526: Minimum Number of Increments on Subarrays to Form a Target Array](https://grid47.xyz/posts/leetcode_1526) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

