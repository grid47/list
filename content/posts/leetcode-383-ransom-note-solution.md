
+++
authors = ["grid47"]
title = "Leetcode 383: Ransom Note"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 383: Ransom Note in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ransom-note/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/383.webp" 
    alt="A sequence of letters forming a ransom note, with the available letters glowing to form the required note."
    caption="Solution to LeetCode 383: Ransom Note Problem"
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
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;
        for(int x: magazine)
            mp[x]++;
        
        for(int j = 0; j < ransomNote.size(); j++) {
            if(!mp.count(ransomNote[j])) return false;
            else {
                mp[ransomNote[j]]--;
                if(mp[ransomNote[j]] == 0) mp.erase(ransomNote[j]);
            }
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/383.md" >}}
---
{{< youtube i3bvxJyUB40 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #384: Shuffle an Array](https://grid47.xyz/posts/leetcode-384-shuffle-an-array-solution/) |
| --- |
