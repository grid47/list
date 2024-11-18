
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
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/820.webp" 
    alt="A series of words encoded, with the shortest encoding glowing softly as it is created."
    caption="Solution to LeetCode 820: Short Encoding of Words Problem"
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #822: Card Flipping Game](https://grid47.xyz/leetcode/solution-822-card-flipping-game/) |
| --- |
