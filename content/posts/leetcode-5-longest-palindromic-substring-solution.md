
+++
authors = ["grid47"]
title = "Leetcode 5: Longest Palindromic Substring"
date = "2024-11-01"
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
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/5.jpeg" 
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #6: Zigzag Conversion](https://grid47.xyz/posts/leetcode-6-zigzag-conversion-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}