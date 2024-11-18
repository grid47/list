
+++
authors = ["grid47"]
title = "Leetcode 1604: Alert Using Same Key-Card Three or More Times in a One Hour Period"
date = "2024-05-30"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1605: Find Valid Matrix Given Row and Column Sums](https://grid47.xyz/leetcode/solution-1605-find-valid-matrix-given-row-and-column-sums/) |
| --- |
