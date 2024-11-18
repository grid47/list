
+++
authors = ["grid47"]
title = "Leetcode 1456: Maximum Number of Vowels in a Substring of Given Length"
date = "2024-06-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1456: Maximum Number of Vowels in a Substring of Given Length in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "tal8tKUr6dU"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int vowels[26] = {  1,0,0,0,1, 0,0,0,1,0, 
                        0,0,0,0,1, 0,0,0,0,0, 
                        1,0,0,0,0, 0 };
    int maxVowels(string s, int k) {
        int mx = 0;
        for(int i = 0, cur = 0; i < s.size(); i++) {
            cur += vowels[s[i] - 'a'];
            if(i >= k) cur -= vowels[s[i-k] - 'a'];
            mx = max(cur, mx);
        }
        return mx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1456.md" >}}
---
{{< youtube tal8tKUr6dU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1457: Pseudo-Palindromic Paths in a Binary Tree](https://grid47.xyz/leetcode/solution-1457-pseudo-palindromic-paths-in-a-binary-tree/) |
| --- |
