
+++
authors = ["grid47"]
title = "Leetcode 820: Short Encoding of Words"
date = "2024-08-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 820: Short Encoding of Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/short-encoding-of-words/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {

        unordered_set<string> s(words.begin(), words.end());
        
        for(string w: words)
        for(int i = 1; i < w.size(); i++)
            s.erase(w.substr(i));

        int res = 0;        
        for(string sk: s)
        res += (sk.size() + 1);
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/820.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #822: Card Flipping Game](https://grid47.xyz/posts/leetcode-822-card-flipping-game-solution/) |
| --- |
