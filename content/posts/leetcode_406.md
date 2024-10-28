
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 406: Queue Reconstruction by Height"
date = "2023-09-19"
description = "Solution to Leetcode 406"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/queue-reconstruction-by-height/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort( people.begin(), people.end(), [] (vector<int> a, vector<int> b) {
            
            return a[0] > b[0] || ((a[0] == b[0]) && a[1] < b[1]);
            
        });
        
        vector<vector<int>> ans;
        for(auto p: people) 
            ans.insert(ans.begin() + p[1], p);
        
        return ans;
        
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

