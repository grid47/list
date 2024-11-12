
+++
authors = ["grid47"]
title = "Leetcode 739: Daily Temperatures"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 739: Daily Temperatures in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/daily-temperatures/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/739.md" >}}
---
{{< youtube _ZEvmycwXHs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #740: Delete and Earn](https://grid47.xyz/posts/leetcode-740-delete-and-earn-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
