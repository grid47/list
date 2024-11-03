
+++
authors = ["Crafted by Me"]
title = "Leetcode 1638: Count Substrings That Differ by One Character"
date = "2020-05-09"
description = "In-depth solution and explanation for Leetcode 1638: Count Substrings That Differ by One Character in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-substrings-that-differ-by-one-character/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0;
        for(int i = 0; i < s.size(); i++)
            res += helper(s, t, i, 0);
        for(int j = 1; j < t.size(); j++)
            res += helper(s, t, 0, j);
        return res;
    }

    int helper(string s, string t, int i, int j) {
        int res = 0, pre = 0, cur = 0;
        for(int n = s.size(), m = t.size(); i < n && j < m; i++, j++) {
            cur++;
            if(s[i] != t[j]) {
                pre = cur;
                cur = 0;
            }
            res += pre;
        }
        return res;
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1639: Number of Ways to Form a Target String Given a Dictionary](https://grid47.xyz/posts/leetcode_1639) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

