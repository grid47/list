
+++
authors = ["Crafted by Me"]
title = "Leetcode 2311: Longest Binary Subsequence Less Than or Equal to K"
date = "2018-07-06"
description = "In-depth solution and explanation for Leetcode 2311: Longest Binary Subsequence Less Than or Equal to K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int val = 0, cnt = 0, pow = 1;
        for(int i = s.size() - 1; i >= 0 && val + pow <= k; i--) {
            if(s[i] == '1') {
                ++cnt;
                val += pow;
            }
            pow <<= 1;
        }
        return count(s.begin(), s.end(), '0') + cnt;  
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2312: Selling Pieces of Wood](grid47.xyz/leetcode_2312) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

