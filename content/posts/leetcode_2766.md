
+++
authors = ["Crafted by Me"]
title = "Leetcode 2766: Relocate Marbles"
date = "2017-04-06"
description = "Solution to Leetcode 2766"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/relocate-marbles/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int, int> mp;  
        for(auto n: nums) mp[n] = 1;
        for(int i = 0; i < moveFrom.size(); ++i){
            if(mp[moveFrom[i]] && moveFrom[i] != moveTo[i]) {
                mp[moveTo[i]] = 1;  mp[moveFrom[i]] = 0;
            }
        }
        vector<int> ans;
        for(auto m: mp) if(m.second) ans.push_back(m.first);
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

