
+++
authors = ["grid47"]
title = "Leetcode 139: Word Break"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 139: Word Break in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Dynamic Programming","Trie","Memoization"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/139.webp"
youtube = "t0svbzZ1PWM"
youtube_upload_date="2021-04-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/t0svbzZ1PWM/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/word-break/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/139.webp" 
    alt="A string breaking into glowing segments, with each segment leading to a valid word in a dictionary."
    caption="Solution to LeetCode 139: Word Break Problem"
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
    vector<int> memo;
    bool wordBreak(string s, vector<string>& dict) {
        map<string, bool> mp;
        for(string d: dict)
            mp[d] = true;
        memo.resize(s.size(), -1);
        return bt(s, 0, mp);
    }
    
    bool bt(string s, int idx, map<string, bool> &mp) {
        
        if(idx == s.size()) return true;
        
        if(memo[idx] != -1) return memo[idx];
        
        for(int i = idx; i < s.size(); i++) {
            if(mp.count(s.substr(idx, i - idx + 1)) && bt(s, i + 1, mp))
                return memo[idx] = true;
        }
        
        return memo[idx] = false;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/139.md" >}}
---
{{< youtube t0svbzZ1PWM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #141: Linked List Cycle](https://grid47.xyz/leetcode/solution-141-linked-list-cycle/) |
| --- |
