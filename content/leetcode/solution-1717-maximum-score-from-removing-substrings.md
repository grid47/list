
+++
authors = ["grid47"]
title = "Leetcode 1717: Maximum Score From Removing Substrings"
date = "2024-05-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1717: Maximum Score From Removing Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "9wZ-TWBreTg"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-score-from-removing-substrings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumGain(string s, int x, int y, char a = 'a', char b = 'b') {
        if(y > x) {
            swap(a, b);
            swap(x, y);
        }
        
        auto s1 = greedy(s, a, b), s2 = greedy(s1,  b, a);
        
        return ((s.size() - s1.size()) / 2) * x + ((s1.size() - s2.size()) / 2) * y;
    }
    string greedy(string s, char a, char b) {
        
        string st;
        
        for(char c : s) {
            if(!st.empty() && st.back() == a && c == b)
                st.pop_back();
            else st.push_back(c);
        }
        return st;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1717.md" >}}
---
{{< youtube 9wZ-TWBreTg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1718: Construct the Lexicographically Largest Valid Sequence](https://grid47.xyz/leetcode/solution-1718-construct-the-lexicographically-largest-valid-sequence/) |
| --- |
