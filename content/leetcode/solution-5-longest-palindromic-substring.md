
+++
authors = ["grid47"]
title = "Leetcode 5: Longest Palindromic Substring"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 5: Longest Palindromic Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-palindromic-substring/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/5.webp" 
    alt="A mirror reflecting a glowing word, with symmetry and balance radiating outward."
    caption="Solution to LeetCode 5: Longest Palindromic Substring Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int lo, len;
    string longestPalindrome(string s) {
        len = 0;
        
        for(int i = 0; i < s.size(); i++) {
            pal(s, i, i);
            pal(s, i, i + 1);
        }
        return s.substr(lo, len);
    }
    
    void pal(string &s, int i, int j) {
        while(i >= 0 && j <= s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        if(len < j - i - 1) {
            lo = i + 1;
            len = j - i - 1;
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/5.md" >}}
---
{{< youtube XYQecbcd6_c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #6: Zigzag Conversion](https://grid47.xyz/leetcode/solution-6-zigzag-conversion/) |
| --- |
