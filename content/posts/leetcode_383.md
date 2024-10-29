
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 383: Ransom Note"
date = "2023-10-13"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

