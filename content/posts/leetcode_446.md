
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 446: Arithmetic Slices II - Subsequence"
date = "2023-08-11"
description = "Solution to Leetcode 446"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<map<int,int>> mp(n);
        for(int i = 0; i < n; i++) {
            mp[i].clear();
            for(int j = 0; j < i; j++) {
                
                long diff = (long) nums[j] - nums[i];
                if(diff < INT_MIN || diff > INT_MAX) continue;
                
                int d = (int) diff;
                
                int c1 = mp[i][d];
                int c2 = mp[j][d];                
                res += c2;
                
                mp[i][d] = c1 + c2 + 1;
            }
        }
        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/446.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
