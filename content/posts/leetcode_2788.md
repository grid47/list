
+++
authors = ["Yasir"]
title = "Leetcode 2788: Split Strings by Separator"
date = "2017-03-12"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

