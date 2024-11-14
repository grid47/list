
+++
authors = ["grid47"]
title = "Leetcode 557: Reverse Words in a String III"
date = "2024-09-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 557: Reverse Words in a String III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-words-in-a-string-iii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/557.webp" 
    alt="A string where the words are reversed, with each word glowing softly as it flips in place."
    caption="Solution to LeetCode 557: Reverse Words in a String III Problem"
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
    string reverseWords(string s) {
        int n = s.size(), prv = 0;
        for(int i = 0; i < n; i++)
            if(s[i] == ' ')
                rev(s, prv, i - 1), prv = i + 1;
            else if(i == n - 1)
                rev(s, prv, i);        
        return s;
    }
    
    void rev(string &s, int i, int j) {
        while(i <= j)
            swap(s[i++], s[j--]);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/557.md" >}}
---
{{< youtube _I57bpDMWnY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #560: Subarray Sum Equals K](https://grid47.xyz/posts/leetcode-560-subarray-sum-equals-k-solution/) |
| --- |
