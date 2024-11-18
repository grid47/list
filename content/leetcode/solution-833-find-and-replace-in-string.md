
+++
authors = ["grid47"]
title = "Leetcode 833: Find And Replace in String"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 833: Find And Replace in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "J6Gtc4haYHg"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/find-and-replace-in-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        /*
        
        string s
        indices - arr of int
        src       arr of str
        tgt       arr of str
        
        */
        
        vector<pair<int, int>> ind;
        
        for(int i = 0; i < indices.size(); i++)
            ind.push_back({indices[i], i});
        
        sort(ind.rbegin(), ind.rend());
        
        for(auto it: ind) {
            string src = sources[it.second], tgt = targets[it.second];
            if(s.substr(it.first, src.size()) == src)
                s = s.substr(0, it.first) + tgt + s.substr(it.first+ src.size());
        }
        
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/833.md" >}}
---
{{< youtube J6Gtc4haYHg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #835: Image Overlap](https://grid47.xyz/leetcode/solution-835-image-overlap/) |
| --- |
