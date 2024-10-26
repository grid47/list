
+++
authors = ["Yasir"]
title = "Leetcode 720: Longest Word in Dictionary"
date = "2022-11-07"
description = "Solution to Leetcode 720"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-word-in-dictionary/description/)

---

**Code:**

{{< highlight html >}}
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

