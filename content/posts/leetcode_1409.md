
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1409: Queries on a Permutation With Key"
date = "2020-12-21"
description = "Solution to Leetcode 1409"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/queries-on-a-permutation-with-key/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> processQueries(vector<int>& q, int m) {
        vector<int> ans;
        for(int i = 1; i <= m; i++)
            ans.push_back(i);
        map<int, int> mp;
        for(int i = 0; i < ans.size(); i++)
            mp[ans[i]] = i;
        
        vector<int> res;
        for(int i = 0; i < q.size(); i++) {
            int x = mp[q[i]];
            res.push_back(x);
            for(auto it: mp) {
                if(it.second < x)
                mp[it.first]++; // shit to right
            }
            mp[q[i]] = 0;
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

