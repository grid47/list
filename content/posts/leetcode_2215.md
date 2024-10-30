
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2215: Find the Difference of Two Arrays"
date = "2018-10-08"
description = "Solution to Leetcode 2215"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-difference-of-two-arrays/description/)

---
{{< youtube oypp_RzI69w >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        set<int> s1, s2;
        for(int i = 0; i < nums1.size(); i++) {
            s1.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            s2.insert(nums2[i]);
        }
        for(int x: s1) {
            if(!s2.count(x))
                ans[0].push_back(x);
        }
        for(int x: s2) {
            if(!s1.count(x))
                ans[1].push_back(x);
        }        
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

