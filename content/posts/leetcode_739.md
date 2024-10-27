
+++
authors = ["Yasir"]
title = "Leetcode 739: Daily Temperatures"
date = "2022-10-20"
description = "Solution to Leetcode 739"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/daily-temperatures/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> stk;
        vector<int> ans(temp.size(), 0);
        for(int i = 0; i < temp.size(); i++) {
            // cout << temp[i] << " " ;
            while(!stk.empty() && temp[i] > stk.top().first) {
                // cout << temp[i] << " " ;
                pair<int, int> x = stk.top();

                // cout << temp[i] << " " ;                
                stk.pop();
                
                // cout << temp[i] << " " << x.first << x.second; 
                ans[x.second] = i-x.second;
                // cout << temp[i] << " " ;
            }
            stk.push(make_pair(temp[i], i));
        }
        
        while(!stk.empty()) {
            auto x = stk.top();
            stk.pop();
            ans[x.second] = 0;
        }
        
        return ans;
    }
};
{{< /highlight >}}

