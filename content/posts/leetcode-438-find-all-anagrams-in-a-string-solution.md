
+++
authors = ["grid47"]
title = "Leetcode 438: Find All Anagrams in a String"
date = "2024-09-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 438: Find All Anagrams in a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/438.webp" 
    alt="A glowing string where anagrams light up and form matching groups as they are found."
    caption="Solution to LeetCode 438: Find All Anagrams in a String Problem"
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
    vector<int> findAnagrams(string s, string p) {
        vector<int> pc(26, 0), sc(26, 0);
        for(char x: p)
            pc[x-'a']++;
        
        vector<int> ans;
        for(int i = 0; i < s.size(); i++) {
            if(i >= p.size()) {
                sc[s[i - p.size()] - 'a']--;
            }
            sc[s[i]-'a']++;
            if(sc == pc) ans.push_back(i - p.size() +1);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/438.md" >}}
---
{{< youtube G8xtZy0fDKg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #443: String Compression](https://grid47.xyz/posts/leetcode-443-string-compression-solution/) |
| --- |
