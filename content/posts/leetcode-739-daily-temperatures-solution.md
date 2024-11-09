
+++
authors = ["grid47"]
title = "Leetcode 739: Daily Temperatures"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #740: Delete and Earn](https://grid47.xyz/posts/leetcode-739-daily-temperatures-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
