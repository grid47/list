
+++
authors = ["Crafted by Me"]
title = "Leetcode 1604: Alert Using Same Key-Card Three or More Times in a One Hour Period"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1604: Alert Using Same Key-Card Three or More Times in a One Hour Period in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<string> alertNames(vector<string>& name, vector<string>& time) {
        
        unordered_map<string, vector<int>> mp;
        
        int n = name.size();
        for(int i = 0; i < n; i++)
        mp[name[i]].push_back(stoi(time[i].substr(0, 2)) * 60 + stoi(time[i].substr(3)));
        
        vector<string> ans;
        for(auto &it: mp) {
            sort(it.second.begin(), it.second.end());
            // cout << it.first << " ";
            // for(auto x: it.second)
            //     cout << x << " ";
            // cout << "\n";            
            for(int i = 0, j = 0; i < it.second.size(); i++) {
                while(it.second[i] - it.second[j] > 60)
                    j++;
                
                if(i - j >= 2) {
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1604.md" >}}
---
{{< youtube gGNxRDPPbgA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1605: Find Valid Matrix Given Row and Column Sums](https://grid47.xyz/posts/leetcode_1605) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

