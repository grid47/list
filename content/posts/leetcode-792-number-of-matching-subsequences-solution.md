
+++
authors = ["grid47"]
title = "Leetcode 792: Number of Matching Subsequences"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 792: Number of Matching Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Binary Search","Dynamic Programming","Trie","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-matching-subsequences/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/792.webp" 
    alt="A sequence where matching subsequences are counted, with each match glowing softly as it is found."
    caption="Solution to LeetCode 792: Number of Matching Subsequences Problem"
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
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        vector<vector<int>> srch(26);

        for(int i = 0; i < s.size(); i++)
            srch[s[i] - 'a'].push_back(i);
        
        int res = 0;
        
        for(string word : words) {
            int x = -1;
            bool found = true;

            for(char c : word) {
                auto it = upper_bound(srch[c - 'a'].begin(), srch[c - 'a'].end(), x);
                if(it == srch[c - 'a'].end()) {
                    found = false;
                    break;
                } else x = *it;
            }
            
            if(found) res++;
        }
                
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/792.md" >}}
---
{{< youtube 0zMujz5SYoE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #794: Valid Tic-Tac-Toe State](https://grid47.xyz/posts/leetcode-794-valid-tic-tac-toe-state-solution/) |
| --- |
