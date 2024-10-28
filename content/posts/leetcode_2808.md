
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2808: Minimum Seconds to Equalize a Circular Array"
date = "2017-02-20"
description = "Solution to Leetcode 2808"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        
        int n = nums.size();
        map<int, vector<int>> pos;
        
        for(int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);
        
        int res = INT_MAX;
        
        for(auto [key, val]: pos) {
            int sec = 0;
            val.push_back(val[0] + n);
            
            for(int i = 1; i < val.size(); i++) {
                sec = max(sec, (val[i] - val[i - 1])/ 2);
            }
            
            res = min(res, sec);
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

