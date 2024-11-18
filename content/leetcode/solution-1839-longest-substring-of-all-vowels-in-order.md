
+++
authors = ["grid47"]
title = "Leetcode 1839: Longest Substring Of All Vowels in Order"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1839: Longest Substring Of All Vowels in Order in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestBeautifulSubstring(string s) {
        map<char, int> idx;
        idx['a'] = 0;
        idx['e'] = 1;
        idx['i'] = 2;
        idx['o'] = 3;
        idx['u'] = 4;
        
        int j = 0, res = 0, n = s.size();
        int id = -1;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                if(id != 0) {                 
                    j = i;
                }
                id = 0;
            }else if((idx[s[i]] < id) || (idx[s[i]] - id > 1)) {
                id = -1;
                j = i;
            } else if(idx[s[i]] - id == 1) {
                id = idx[s[i]];
                
            }
            
            if(id == 4) {
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1839.md" >}}
---
{{< youtube hhyzRnwYBwA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1844: Replace All Digits with Characters](https://grid47.xyz/leetcode/solution-1844-replace-all-digits-with-characters/) |
| --- |
