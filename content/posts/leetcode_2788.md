
+++
authors = ["Crafted by Me"]
title = "Leetcode 2788: Split Strings by Separator"
date = "2016-03-15"
description = "Solution to Leetcode 2788"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-strings-by-separator/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char sep) {
        
        vector<string> ans;
        
        for(int i = 0; i < words.size(); i++) {
            string cur = "";
            
            for(int j = 0; j < words[i].size(); j++) {
                if(words[i][j] == sep) {
                    if(cur != "")
                    ans.push_back(cur);
                    cur = "";
                } else if(j == words[i].size() - 1) {
                    cur += words[i][j];                    
                    ans.push_back(cur);
                    cur = "";
                } else 
                cur += words[i][j];
            }
            
        }
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

