
+++
authors = ["Yasir"]
title = "Leetcode 2191: Sort the Jumbled Numbers"
date = "2018-10-30"
description = "Solution to Leetcode 2191"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-the-jumbled-numbers/description/)

---

**Code:**

{{< highlight html >}}
#include <string.h>
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> tmp;
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            
            int num = nums[i];
            
            string str = to_string(num);
            string formed = "";
            for(int j = 0; j < str.size(); j++)
                formed += to_string(mapping[str[j]- '0']);
            int val = stoi(formed);
            tmp.push_back({ val, i });
            
        }
        
        sort(tmp.begin(), tmp.end());
        
        vector<int> ans;
        for(int i = 0; i < n; i++)
            ans.push_back(nums[tmp[i].second]);
        
        return ans;
        
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

