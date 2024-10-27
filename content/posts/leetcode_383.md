
+++
authors = ["Yasir"]
title = "Leetcode 383: Ransom Note"
date = "2023-10-11"
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

{{< highlight html >}}
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

