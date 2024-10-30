
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1268: Search Suggestions System"
date = "2021-05-12"
description = "Solution to Leetcode 1268"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/search-suggestions-system/description/)

---
{{< youtube PLNDfB0Vg9Y >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string w) {
        auto it = A.begin();
        sort(it, A.end());
        vector<vector<string>> res;
        string cur = "";
        for (char c : w) {
            cur += c;
            vector<string> sdg;
            it = lower_bound(it, A.end(), cur);
for(int i = 0; i < 3 && (it + i) != A.end(); i++) {
                
        string& s = *(i + it);
        if(s.find(cur)) break;
        sdg.push_back(s);
                
            }
            res.push_back(sdg);
        }
        
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

