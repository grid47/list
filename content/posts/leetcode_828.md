
+++
authors = ["Crafted by Me"]
title = "Leetcode 828: Count Unique Characters of All Substrings of a Given String"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 828: Count Unique Characters of All Substrings of a Given String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int uniqueLetterString(string s) {

        vector<vector<int>> idx(26, vector<int>(2, -1));
        
        int n = s.size();
        
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            res += (i - idx[c][1]) * (idx[c][1] - idx[c][0]);
            idx[c][0] = idx[c][1];
            idx[c][1] = i;
        }
        
        for(int i = 0; i < 26; i++)
            res += (n - idx[i][1]) * (idx[i][1] - idx[i][0]);
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/828.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #829: Consecutive Numbers Sum](https://grid47.xyz/posts/leetcode_829) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

