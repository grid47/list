
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 757: Set Intersection Size At Least Two"
date = "2022-10-03"
description = "Solution to Leetcode 757"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/set-intersection-size-at-least-two/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [&](vector<int> &a, vector<int> &b){
            if(a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });
        
        int ans = 0, fst = -1, scd = -1;
        
        for(auto it: nums) {
            int a = it[0], b = it[1];
            
            bool is_fst_in = a <= fst;
            bool is_scd_in = a <= scd;
            
            if(is_fst_in && is_scd_in) continue;
            
            ans += is_fst_in ? 1: 2;
            
            scd = is_fst_in? fst: b-1;
            fst = b;
            
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

