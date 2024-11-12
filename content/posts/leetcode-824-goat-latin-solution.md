
+++
authors = ["grid47"]
title = "Leetcode 824: Goat Latin"
date = "2024-08-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 824: Goat Latin in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/goat-latin/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string toGoatLatin(string str) {
        stringstream iss(str), oss;
        set<char> s = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string word;
        string a;
        while(iss >> word) {
            a.push_back('a');
            if(s.count(word[0])) {
                oss << ' ' << word << "ma" << a;
            } else {
                oss << ' ' << word.substr(1) << word[0]  << "ma" << a;                
            }
        }
        return oss.str().substr(1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/824.md" >}}
---
{{< youtube pTLNHVWiQk0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #825: Friends Of Appropriate Ages](https://grid47.xyz/posts/leetcode-825-friends-of-appropriate-ages-solution/) |
| --- |
