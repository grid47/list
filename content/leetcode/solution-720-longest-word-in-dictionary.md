
+++
authors = ["grid47"]
title = "Leetcode 720: Longest Word in Dictionary"
date = "2024-08-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 720: Longest Word in Dictionary in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Trie","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "t2jdltmqnlY"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/720.webp"
+++



[`Problem Link`](https://leetcode.com/problems/longest-word-in-dictionary/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/720.webp" 
    alt="A dictionary where the longest word is highlighted, softly glowing as it stands out."
    caption="Solution to LeetCode 720: Longest Word in Dictionary Problem"
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
    string longestWord(vector<string>& words) {
    
        sort(words.begin(),words.end());
        unordered_set<string> mp;
        string res="";
        
        for(string w: words){
            if(w.size() == 1 || mp.count(w.substr(0, w.size() -1))) {
                res = w.size()>res.size()? w:res;
                mp.insert(w);
            }
        }
        return res;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/720.md" >}}
---
{{< youtube t2jdltmqnlY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #721: Accounts Merge](https://grid47.xyz/leetcode/solution-721-accounts-merge/) |
| --- |
