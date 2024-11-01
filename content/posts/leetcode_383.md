
+++
authors = ["Crafted by Me"]
title = "Leetcode 383: Ransom Note"
date = "2023-10-16"
description = "Solution to Leetcode 383"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/ransom-note/description/)

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
- by gpt
        
---
{{< youtube i3bvxJyUB40 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

