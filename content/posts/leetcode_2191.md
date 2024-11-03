
+++
authors = ["Crafted by Me"]
title = "Leetcode 2191: Sort the Jumbled Numbers"
date = "2018-11-03"
description = "In-depth solution and explanation for Leetcode 2191: Sort the Jumbled Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

