
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1452: People Whose List of Favorite Companies Is Not a Subset of Another List"
date = "2020-11-07"
description = "Solution to Leetcode 1452"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& comp) {
        int n = comp.size();
        
        for(auto &c : comp)
            sort(c.begin(), c.end());
        
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int notSubset = true;
            
            for(int j = 0; j < n && notSubset; j++) {
                if(i == j) continue;
                
                notSubset = !includes(comp[j].begin(), comp[j].end(), comp[i].begin(), comp[i].end());
            }
            if(notSubset)
                res.push_back(i);
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

