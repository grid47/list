
+++
authors = ["grid47"]
title = "Leetcode 1813: Sentence Similarity III"
date = "2024-05-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1813: Sentence Similarity III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "MMMd7dMv4Ak"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/sentence-similarity-iii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        
        deque<string> a, b;
        string tmp = "";
        
        for(char c: s1) {
            if(c == ' ') a.push_back(tmp), tmp = "";
            else tmp += c;
        }
        a.push_back(tmp), tmp = "";
        for(char c: s2) {
            if(c == ' ') b.push_back(tmp), tmp = "";
            else tmp += c;
        }        
        b.push_back(tmp), tmp = "";
        
        while(a.size() != 0 && b.size() != 0 && (a.front() == b.front())) a.pop_front(), b.pop_front();
        while(a.size() != 0 && b.size() != 0 && (a.back() == b.back())) a.pop_back(), b.pop_back();
        
        if(a.size() == 0 || b.size() == 0) return true;
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1813.md" >}}
---
{{< youtube MMMd7dMv4Ak >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1814: Count Nice Pairs in an Array](https://grid47.xyz/leetcode/solution-1814-count-nice-pairs-in-an-array/) |
| --- |
