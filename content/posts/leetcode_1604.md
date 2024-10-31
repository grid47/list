
+++
authors = ["Crafted by Me"]
title = "Leetcode 1604: Alert Using Same Key-Card Three or More Times in a One Hour Period"
date = "2020-06-11"
description = "Solution to Leetcode 1604"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

